//DJN Co.,LTD.
//LCM operation code
//Driver IC: ILI9325
//Panel: CPT 2.4

/********************************************************************************
  DESCRIPTION:
 LCM initialization sequence.
  PARAMETERS:
  RETURNS:
  REMARKS:
*********************************************************************************/ 
void ILI9325_wintek24_Initial(void)
{
 // VCI=2.8V
 //************* Reset LCD Driver ****************//
 LCD_nRESET = 1;
 delayms(1); // Delay 1ms
 LCD_nRESET = 0;
 delayms(10); // Delay 10ms // This delay time is necessary
 LCD_nRESET = 1;
 delayms(50); // Delay 50 ms
 //************* Start Initial Sequence **********//
 LCD_CtrlWrite_ILI9325(0x00E3, 0x3008); // Set internal timing
 LCD_CtrlWrite_ILI9325(0x00E7, 0x0012); // Set internal timing
 LCD_CtrlWrite_ILI9325(0x00EF, 0x1231); // Set internal timing
 LCD_CtrlWrite_ILI9325(0x0001, 0x0100); // set SS and SM bit
 LCD_CtrlWrite_ILI9325(0x0002, 0x0700); // set 1 line inversion
 LCD_CtrlWrite_ILI9325(0x0003, 0x1030); // set GRAM write direction and BGR=1.
 LCD_CtrlWrite_ILI9325(0x0004, 0x0000); // Resize register
 LCD_CtrlWrite_ILI9325(0x0008, 0x0202); // set the back porch and front porch
 LCD_CtrlWrite_ILI9325(0x0009, 0x0000); // set non-display area refresh cycle ISC[3:0]
 LCD_CtrlWrite_ILI9325(0x000A, 0x0000); // FMARK function
 LCD_CtrlWrite_ILI9325(0x000C, 0x0000); // RGB interface setting
 LCD_CtrlWrite_ILI9325(0x000D, 0x0000); // Frame marker Position
 LCD_CtrlWrite_ILI9325(0x000F, 0x0000); // RGB interface polarity
 //*************Power On sequence ****************//
 LCD_CtrlWrite_ILI9325(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
 LCD_CtrlWrite_ILI9325(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
 LCD_CtrlWrite_ILI9325(0x0012, 0x0000); // VREG1OUT voltage
 LCD_CtrlWrite_ILI9325(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude
 delayms(200); // Dis-charge capacitor power voltage
 LCD_CtrlWrite_ILI9325(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB
 LCD_CtrlWrite_ILI9325(0x0011, 0x0227); // R11h=0x0221 at VCI=3.3V, DC1[2:0], DC0[2:0], VC[2:0]
 delayms(50); // Delay 50ms
 LCD_CtrlWrite_ILI9325(0x0012, 0x001C); // External reference voltage= Vci;
 delayms(50); // Delay 50ms
 LCD_CtrlWrite_ILI9325(0x0013, 0x1800); // R13=1200 when R12=009D;VDV[4:0] for VCOM amplitude
 LCD_CtrlWrite_ILI9325(0x0029, 0x001C); // R29=000C when R12=009D;VCM[5:0] for VCOMH
 LCD_CtrlWrite_ILI9325(0x002B, 0x000D); // Frame Rate = 91Hz
 delayms(50); // Delay 50ms
 LCD_CtrlWrite_ILI9325(0x0020, 0x0000); // GRAM horizontal Address
 LCD_CtrlWrite_ILI9325(0x0021, 0x0000); // GRAM Vertical Address
 // ----------- Adjust the Gamma Curve ----------//
 LCD_CtrlWrite_ILI9325(0x0030, 0x0007);
 LCD_CtrlWrite_ILI9325(0x0031, 0x0302);
 LCD_CtrlWrite_ILI9325(0x0032, 0x0105);
 LCD_CtrlWrite_ILI9325(0x0035, 0x0206);
 LCD_CtrlWrite_ILI9325(0x0036, 0x0808);
 LCD_CtrlWrite_ILI9325(0x0037, 0x0206);
 LCD_CtrlWrite_ILI9325(0x0038, 0x0504);
 LCD_CtrlWrite_ILI9325(0x0039, 0x0007);
 LCD_CtrlWrite_ILI9325(0x003C, 0x0105);
 LCD_CtrlWrite_ILI9325(0x003D, 0x0808);
 //------------------ Set GRAM area ---------------//
 LCD_CtrlWrite_ILI9325(0x0050, 0x0000); // Horizontal GRAM Start Address
 LCD_CtrlWrite_ILI9325(0x0051, 0x00EF); // Horizontal GRAM End Address
 LCD_CtrlWrite_ILI9325(0x0052, 0x0000); // Vertical GRAM Start Address
 LCD_CtrlWrite_ILI9325(0x0053, 0x013F); // Vertical GRAM Start Address
 LCD_CtrlWrite_ILI9325(0x0060, 0xA700); // Gate Scan Line
 LCD_CtrlWrite_ILI9325(0x0061, 0x0001); // NDL,VLE, REV
 LCD_CtrlWrite_ILI9325(0x006A, 0x0000); // set scrolling line
 //-------------- Partial Display Control ---------//
 LCD_CtrlWrite_ILI9325(0x0080, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0081, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0082, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0083, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0084, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0085, 0x0000);
 //-------------- Panel Control -------------------//
 LCD_CtrlWrite_ILI9325(0x0090, 0x0010);
 LCD_CtrlWrite_ILI9325(0x0092, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0093, 0x0003);
 LCD_CtrlWrite_ILI9325(0x0095, 0x0110);
 LCD_CtrlWrite_ILI9325(0x0097, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0098, 0x0000);
 LCD_CtrlWrite_ILI9325(0x0007, 0x0133); // 262K color and display ON
}
 
 
/********************************************************************************
  DESCRIPTION:
 LCM display window setting.
  PARAMETERS:
 xs: Horizontal Address Start Position
 xe: Horizontal Address End Position
 ys: Vertical Address Start Position
 ye: Vertical Address End Position
  RETURNS:
  REMARKS:
*********************************************************************************/
void LCD_set_Window_ILI9325(int xs,int xe,int ys,int ye)
{
 LCD_CtrlWrite_ILI9325(0x0050,xs);
 LCD_CtrlWrite_ILI9325(0x0051,xe);
 LCD_CtrlWrite_ILI9325(0x0052,ys);
 LCD_CtrlWrite_ILI9325(0x0053,ye); 
 LCD_CtrlWrite_ILI9325(0x0020,xs);
 LCD_CtrlWrite_ILI9325(0x0021,ys); 
 LCD_WRITE_CMD(0x0022); 
}
 
/********************************************************************************
  DESCRIPTION:
 LCM enter_sleep_mode sequence.
  PARAMETERS:
  RETURNS:
  REMARKS:
*********************************************************************************/  
void LCD_EnterSleep_lil9325(void)
{
 LCD_CtrlWrite_ILI9325(0x0007,0x0131);//setD1=0,D0=1
 delayms(10);
 LCD_CtrlWrite_ILI9325(0x0007,0x0130);//setD1=0,D0=0
 delayms(10);
 LCD_CtrlWrite_ILI9325(0x0007,0x0000);//displayoff 
 //power off sequence
 LCD_CtrlWrite_ILI9325(0x0010,0x0000);//SAP,BT[3:0],AP,DSTB,SLP,STB
 LCD_CtrlWrite_ILI9325(0x0011,0x0000);//DC1[2:0],DC0[2:0],VC[2:0]
 LCD_CtrlWrite_ILI9325(0x0012,0x0000);//VREG1OUTvoltage
 LCD_CtrlWrite_ILI9325(0x0013,0x0000);//VDV[4:0]forVCOMamplitude
 delayms(200);//dis-chargecapacitorpowervoltage
 LCD_CtrlWrite_ILI9325(0x0010,0x0002);//SAP,BT[3:0],APE,AP,DSTB,SLP
}
 
/********************************************************************************
  DESCRIPTION:
 LCM exit_sleep_mode sequence.
  PARAMETERS:
  RETURNS:
  REMARKS:
*********************************************************************************/
void LCD_ExitSleep_ILI9325(void)
{
 //Power On sequence
 LCD_CtrlWrite_ILI9325(0x0010,0x0000);  // SAP, BT[3:0], AP, DSTB, SLP, STB
 LCD_CtrlWrite_ILI9325(0x0011,0x0007);  //DC1[2:0], DC0[2:0], VC[2:0]
 LCD_CtrlWrite_ILI9325(0x0012,0x0000);  //VREG1OUT voltage
 LCD_CtrlWrite_ILI9325(0x0013,0x0000);   //VDV[4:0] for VCOM amplitude
 delayms(200);
 LCD_CtrlWrite_ILI9325(0x0010,0x1490);  //SAP, BT[3:0], AP, DSTB, SLP, STB
 LCD_CtrlWrite_ILI9325(0x0011,0x0227);  //DC1[2:0], DC0[2:0], VC[2:0]
                  delayms(50);
 LCD_CtrlWrite_ILI9325(0x0012,0x001C);  //External reference voltage=Vci
 delayms(50);
 LCD_CtrlWrite_ILI9325(0x0013,0x1800);  //VDV[4:0] for VCOM amplitude
 LCD_CtrlWrite_ILI9325(0x0029,0x001C);  //VCM[4:0] for VCOMH
 delayms(50);
 LCD_CtrlWrite_ILI9325(0x0007,0x0133);// 
}
