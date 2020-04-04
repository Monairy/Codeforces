///////////////////////////////////////
///////////_QUESTION_1_///////////////
/////////////////////////////////////
void IntPF4_Init(void)
{
SYSCTL_RCGCGPIO_R |= 0x20; //enable portf
GPIO_PORTF_DIR_R &= ~0x10; //PF4 I/P
GPIO_PORTF_AFSEL_R &= ~0x10; //disable AF
GPIO_PORFT_AMSEL_R &= ~0x10; //disable analog
GPIO_PORTF_DEN_R |= 0x10; //enable digital
GPIO_PCTL_R &= ~0x0F0000;
GPIO_PORTF_PUR_R |= 0x10; //enable pullup
GPIO_PORTF_IS_R &= ~0x10; //edge sensitive
GPIO_PORTF_IBE_R &= ~0x10;
GPIO_PORTF_IEV_R &= ~0x10; //falling edge
GPIO_PORTF_ICR_R =0x10;
GPIO_PORTF_IM_R |= 0x10;
NVIC_EN0_R= 0x40000000;
NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF)  | 0x00400000; //priority=2
}
void ST_Init(void)
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x0005;
}
void ST_Wait(uint32_t delay)
{
    NVIC_ST_RELOAD_R = delay - 1;
    NVIC_ST_CURRENT_R = 0;
    while( (NVIC_ST_CTRL_R & 0X00010000) == 0);  
}
void ST_10ms(uint32_t delay)
{
    for(int i=0; i<delay; i++)
    {
        systick_wait(800000);
    }
}
void GPIO_PORTF_Handler(void)
{
	GPIO_PORTF_ICR_R =0x10;
	ST_Init();
	GPIO_PORTF_DEN_R |= 0x0e;   //00001110
    GPIO_PORFT_AMSEL_R &= ~0x0e;  //11110001
	GPIO_PORTF_AFSEL_R &= ~0x0e;   //11110001
	GPIO_PORTF_DIR_R |= 0x0e;  //00001110
	for (uint_8 counter=0; i<=7;i++)
	 { 
      GPIO_PORTF_DATA_R &= ~0x0e; //11110001	
	  GPIO_PORTF_DATA_R |= counter<<1;
	  ST_10ms(100);
	 }
	for (uint_8 counter=7; i=7;i--)
	 { 
      GPIO_PORTF_DATA_R &= ~0x0e; //11110001	
	  GPIO_PORTF_DATA_R |= counter<<1;
	  ST_10ms(100);
	}
}

///////////////////////////////////////
///////////_QUESTION_2_///////////////
/////////////////////////////////////
void Systick(void)
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 8000000-1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_PRI7_R = (NVIC_PRI7_R & 0x00FFFF) | 0x20000000; 
	NVIC_ST_CTRL_R = 0x07;
	enable_interrupt();
	while( (NVIC_ST_CTRL_R & 0X00010000) == 0); 
} 

void SystickHandler(void)
{
	cnt10ms = cnt10ms+1;
}

///////////////////////////////////////
///////////_QUESTION_3_///////////////
/////////////////////////////////////
void Timer3_Init(long period)
{
    SYSCTL_RCGCTIMER_R |= 0x08;
    TIMER3_CTL_R = 0;
    TIMER3_CFG_R = 0;
    TIMER3_TAMR = 0x02; //periodic
    TIMER3_TAILR_R = period - 1;
    TIMER3_TAPR_R = 0;
    TIMER3_ICR_R = 0x01;
    TIMER3_IMR_R = 0x01;
    NVIC_EN1_R = 1 << (35-32);
    TIMER3_CTL_R = 0x01;
}
void Timer3_Handler(void)
{
    TIMER3_ICR_R = 0x01;
    cnt10ms = cnt10ms + 1;
}
void main(void)
{  cnt10ms = 0 ;
   Timer3_Init(80000);
   while(1)
    {
        if( (cnt10ms%10) == 0)
        {Task1();}
        if( (cnt10ms%20) == 0)
        {Task2();}
        if( (cnt10ms%30) == 0)
        {Task3();}
    }
}

///////////////////////////////////////
///////////_QUESTION_4_///////////////
/////////////////////////////////////
void Timer3_Init(long period,uint8_t on)
{
	if(on ==1){SYSCTL_RCGCTIMER_R |= 0x08;}
    if(on ==0){SYSCTL_RCGCTIMER_R &= ~0x08;}
    TIMER3_CTL_R = 0;
    TIMER3_CFG_R = 0;
    TIMER3_TAMR = 0x02; //Periodic
    TIMER3_TAILR_R = period - 1;
    TIMER3_TAPR_R = 0;
    TIMER3_ICR_R = 0x01;
    TIMER3_IMR_R = 0x01;
    NVIC_EN1_R = 1 << (35-32);
    TIMER3_CTL_R = 0x01;
}
void Timer3_Handler(void)
{
    TIMER3_ICR_R = 0x01;
    btnPressTimeMS = btnPressTimeMS + 1;
}

void IntPF4_Init(void)
{
SYSCTL_RCGCGPIO_R |= 0x20; //enable portf
GPIO_PORTF_DIR_R &= ~0x10; //PF4 input
GPIO_PORTF_AFSEL_R &= ~0x10; //disable 
GPIO_PORFT_AMSEL_R &= ~0x10;
GPIO_PORTF_DEN_R |= 0x10;
GPIO_PCTL_R &= ~0x0F0000;
GPIO_PORTF_PUR_R |= 0x10;
GPIO_PORTF_IS_R &= ~0x10; //edge sensitive
GPIO_PORTF_IBE_R |= 0x10; //both edges
GPIO_PORTF_ICR_R =0x10;
GPIO_PORTF_IM_R |= 0x10;
NVIC_EN0_R= 0x40000000;
NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF)  | 0x00600000; //priority=3
}
void GPIO_PORTF_Handler(void)
{
	GPIO_PORTF_ICR_R =0x10;
	if ((GPIO_PORTF_DATA_R & 0x10) ==0)) //falling edge
	{
	  btnPressTimeMS=0;
	  Timer3_Init(80000,1); 
	}
	if ((GPIO_PORTF_DATA_R & 0x10) ==1)) // rising edge
	{
		Timer3_Init(80000,0);
	}
}
