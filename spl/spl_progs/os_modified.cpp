//timer interrupt
loadi(4,17);
loadi(5,18);

//shared library
loadi(63,13);
loadi(64,14);

//init programme
loadi(65,7);
loadi(66,8);

//INT 10
loadi(22,35);
loadi(23,36);

//Exception handler
loadi(2,15);
loadi(3,16);

//INT 7
loadi(16,29);
loadi(17,30);

//IDLE process
loadi(69,11);
loadi(70,12);

//Module 7
loadi(54,67);
loadi(55,68);

//--------------------------------------------------

SP=82*512-1;
call MOD_7;


PTBR=PAGE_TABLE_BASE; //for IDLE Process we use first 16 words since its PID=0
PTLR=10;

//Library
[PTBR+0] = -1;
[PTBR+1] = "0000";
[PTBR+2] = -1;
[PTBR+3] = "0000";

//Heap
[PTBR+4] = -1;
[PTBR+5] = "0000";
[PTBR+6] = -1;
[PTBR+7] = "0000";

//Code
[PTBR+8] = 69;
[PTBR+9] = "0100";
[PTBR+10] = 70;
[PTBR+11] = "0100";
[PTBR+12] = -1;
[PTBR+13] = "0000";
[PTBR+14] = -1;
[PTBR+15] = "0000";

//Stack
[PTBR+16] = 81;
[PTBR+17] = "0110";
[PTBR+18] = -1;
[PTBR+19] = "0000";

[PROCESS_TABLE+1]=0;
[PROCESS_TABLE+11]=82;
[PROCESS_TABLE+4]=RUNNING;

[PROCESS_TABLE+13]=8*512;
[PROCESS_TABLE+12]=0;
[PROCESS_TABLE+14]=PAGE_TABLE_BASE;
[PROCESS_TABLE+15]=10;


[SYSTEM_STATUS_TABLE+1]=0;

[81 * 512] = [69*512 + 1];
SP=8*512;
ireturn;

//---------------------------------------
PTBR=PAGE_TABLE_BASE+20;
PTLR=10;

//Library
[PTBR+0]=63;
[PTBR+1]="0100";
[PTBR+2]=64;
[PTBR+3]="0100";

//Heap
[PTBR+4]=78;
[PTBR+5]="0110";
[PTBR+6]=79;
[PTBR+7]="0110";

//Code
[PTBR+8]=65;
[PTBR+9]="0100";
[PTBR+10]=66;
[PTBR+11]="0100";
[PTBR+12]=-1;
[PTBR+13]="0000";
[PTBR+14]=-1;
[PTBR+15]="0000";

//Stack
[PTBR+16]=76;
[PTBR+17]="0110";
[PTBR+18]=77;
[PTBR+19]="0110";


[PROCESS_TABLE+16+11]=80;
[PROCESS_TABLE+16+1]=1;
[PROCESS_TABLE+16+4]=RUNNING;
[PROCESS_TABLE+16+13]=8*512;
[PROCESS_TABLE+16+12]=0;
[PROCESS_TABLE+16+14]=PAGE_TABLE_BASE+20;
[PROCESS_TABLE+16+15]=10;

[SYSTEM_STATUS_TABLE+1]=1;

[76*512]=[65*512+1];
SP=8*512;

//Initialising machine's PTBR and PTLR for Scheduling INIT process
PTBR=PAGE_TABLE_BASE+20;
PTLR=10;


ireturn;








