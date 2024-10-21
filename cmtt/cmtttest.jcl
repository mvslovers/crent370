//CMTTTEST JOB CLASS=A,REGION=0K,MSGCLASS=A,TIME=1440            
//*                                                              
//LKED     EXEC PGM=IEWL,                                        
//         PARM='SIZE=(4000K,40K),LIST,MAP,XREF,RENT'            
//SYSPRINT DD SYSOUT=*                                           
//SYSLIB   DD DISP=SHR,DSN=MDR.CRENT370.NCALIB,DCB=BLKSIZE=32760 
//SYSLMOD  DD DISP=SHR,DSN=MDR.CRENT370.LINKLIB                  
//SYSUT1   DD UNIT=SYSALLDA,SPACE=(CYL,(2,1))                    
//NCALIB   DD DISP=SHR,DSN=MDR.CRENT370.NCALIB                   
//SYSLIN   DD DDNAME=SYSIN                                       
//SYSIN    DD *                                                  
  INCLUDE SYSLIB(@@CRT0)                                         
  INCLUDE NCALIB(CMTTTEST)                                       
  ENTRY @@CRT0                                                   
  NAME CMTTTEST(R)                                               
/*                                                               
//*                                                              
//TEST     EXEC PGM=CMTTTEST                                     
//STEPLIB  DD DISP=SHR,DSN=MDR.CRENT370.LINKLIB                  
//SYSTERM  DD SYSOUT=*              STDERR                       
//SYSPRINT DD SYSOUT=*              STDOUT                       
//SYSIN    DD DUMMY                 STDIN                        
//                                                               

