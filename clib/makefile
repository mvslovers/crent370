#
# makefile for crent370/jes c files
#
# c2asm370 compiler flags
INC1 := -I.
INC2 := -I/home/mike/repos/crent370/include
CC := c2asm370
CFLAGS := -fverbose-asm -S -O1 $(INC1) $(INC2)
#
# c source code files
C_FILES := abort.c \
	@@abrpt.c \
	abs.c \
	acos.c \
	@@apfset.c \
	@@aradd.c \
	@@aradf.c \
	@@arcou.c \
	@@ardel.c \
	@@areach.c \
	@@arfre.c \
	@@arget.c \
	@@arnew.c \
	@@arsiz.c \
	@@ascb.c \
	asctime.c \
	asin.c \
	@@assert.c \
	atan2.c \
	atan.c \
	atexit.c \
	atof.c \
	atoi.c \
	atol.c \
	@@austep.c \
	@@autask.c \
	@@autcde.c \
	@@autnam.c \
	@@b64dec.c \
	@@b64enc.c \
	@@b64tbl.c \
	bcopy.c \
	@@bldl.c \
	bsearch.c \
	@@call.c \
	@@caller.c \
	calloc.c \
	ceil.c \
	@@cibdel.c \
	@@cibget.c \
	@@cibset.c \
	clearerr.c \
	clibary.c \
	clock.c \
	cos.c \
	cosh.c \
	@@cpclos.c \
	@@cpopen.c \
	@@cppoin.c \
	@@cpread.c \
	@@crtget.c \
	@@crtres.c \
	@@crtset.c \
	@@cs.c \
	@@ctcrte.c \
	@@ctcrtx.c \
	@@ctdel.c \
	@@ctdet.c \
	@@ctfind.c \
	@@ctgtcb.c \
	ctime.c \
	@@ctlock.c \
	@@ctpop.c \
	@@ctpost.c \
	@@ctpush.c \
	@@ctself.c \
	@@cttwat.c \
	@@ctwait.c \
	@@ctyiel.c \
	@@dblcvt.c \
	@dbleps.c \
	@dblmax.c \
	@dblmin.c \
	@@dec.c \
	@@delete.c \
	difftime.c \
	div.c \
	@@doperm.c \
	@@dscbav.c \
	@@dscbdv.c \
	@@dscbv.c \
	@@ecbpst.c \
	@@ecbtwa.c \
	@@ecbtw.c \
	@@ecbtwl.c \
	@@ecbwa.c \
	@@ecbwl.c \
	@@ecbwt.c \
	@@enqdeq.c \
	@@envvar.c \
	@@errno.c \
	@@estae.c \
	@@examin.c \
	@@exit.c \
	exit.c \
	exp.c \
	fabs.c \
	fclose.c \
	fctprtf@.c \
	@@fdclr.c \
	feof.c \
	ferror.c \
	@@fflush.c \
	fflush.c \
	@@fgetc.c \
	fgetc.c \
	fgetpos.c \
	@@fgets.c \
	fgets.c \
	@@fildef.c \
	@@finden.c \
	floor.c \
	@flteps.c \
	@fltmax.c \
	@fltmin.c \
	fmod.c \
	@@fmtisp.c \
	@@fmtloa.c \
	@@fndcde.c \
	fopen.c \
	@@fpfree.c \
	@@fpmode.c \
	@@fpnew.c \
	@@fpold.c \
	@@fpopen.c \
	fprintf.c \
	@@fpshr.c \
	@@fpstar.c \
	@@fptmp.c \
	@@fputc.c \
	fputc.c \
	@@fputs.c \
	fputs.c \
	@@fread.c \
	fread.c \
	free.c \
	@@freeds.c \
	@@freevl.c \
	@@freepd.c \
	freopen.c \
	frexp.c \
	@@frtx99.c \
	@@frtx9a.c \
	fscanf.c \
	@@fseek.c \
	fseek.c \
	fsetpos.c \
	ftell.c \
	@@fwrite.c \
	fwrite.c \
	getc.c \
	getchar.c \
	getenv.c \
	getenvi.c \
	@@get@er.c \
	getmain.c \
	@@getpso.c \
	gets.c \
	gmtime.c \
	gmtimer.c \
	@@grtget.c \
	@@grtres.c \
	@@grtset.c \
	@@gtcom.c \
	@@gterr.c \
	@@gtin.c \
	@@gtout.c \
	hello.c \
	idcams.c \
	@@idecth.c \
	iefssreq.c \
	ikjct441.c \
	@@inaton.c \
	@@inc.c \
	initssob.c \
	@@irallc.c \
	isalnum.c \
	isalpha.c \
	@@isauth.c \
	@@isbuf.c \
	iscntrl.c \
	isdigit.c \
	isgraph.c \
	@@isleap.c \
	islower.c \
	isprint.c \
	ispunct.c \
	isspace.c \
	@@issup.c \
	isupper.c \
	isxdigit.c \
	@@jobid.c \
	@@jobnam.c \
	@@jpaget.c \
	@@jsclos.c \
	@@jsopen.c \
	@@jsrd4.c \
	labs.c \
	ldexp.c \
	ldiv.c \
	@@link.c \
	@@linkds.c \
	@@linkt.c \
	@@listc.c \
	@@listds.c \
	@@listpd.c \
	@@listvl.c \
	@@lk.c \
	@@lkrn.c \
	@@lkrnf.c \
	@@lkrnte.c \
	@@lkrntf.c \
	@@lkrntr.c \
	@@lkrnuf.c \
	@@lkrnun.c \
	@@lkrtef.c \
	@@lktest.c \
	@@lktry.c \
	@@lkunlk.c \
	@@lkuntf.c \
	@@lkuntr.c \
	@@load.c \
	loadenv.c \
	@@loadhi.c \
	localtim.c \
	localtmr.c \
	@@locate.c \
	log10.c \
	log.c \
	@@longj.c \
	longjmp.c \
	malloc.c \
	mblen.c \
	mbstowcs.c \
	mbtowc.c \
	memchr.c \
	memcmp.c \
	memcpy.c \
	memcpyp.c \
	memmove.c \
	memset.c \
	mktime.c \
	modf.c \
	@@mtd.c \
	mtxavail.c \
	mtxclup.c \
	mtxfree.c \
	mtxheld.c \
	mtxinit.c \
	mtxlock.c \
	mtxnew.c \
	mtxnheld.c \
	mtxtry.c \
	mtxunlk.c \
	@@nwtx99.c \
	@@nwtx9a.c \
	@@nwtx9s.c \
	on@exit.c \
	@@patmat.c \
	@@perm.c \
	perror.c \
	pow.c \
	printf.c \
	printf@.c \
	@@prob.c \
	@@prtfx.c \
	@@pswkey.c \
	putc.c \
	putchar.c \
	putenv.c \
	puts.c \
	qsort.c \
	raise.c \
	rand.c \
	rclose.c \
	@@rdjfcb.c \
	realloc.c \
	remove.c \
	rename.c \
	@@reopen.c \
	rewind.c \
	ropen.c \
	rread.c \
	rwrite.c \
	scanf.c \
	setbuf.c \
	setenv.c \
	setenvi.c \
	setlocal.c \
	setvbuf.c \
	@@sigdfl.c \
	@@sigerr.c \
	@@sighdl.c \
	@@sigign.c \
	signal.c \
	sin.c \
	sinh.c \
	@@sl.c \
	sleep.c \
	@@sltest.c \
	@@sltry.c \
	@@slunlk.c \
	@@smca.c \
	@@smfid.c \
	snprintf.c \
	snprtf@.c \
	@@soadd.c \
	@@sodel.c \
	@@sofind.c \
	@@soupd.c \
	sprintf.c \
	sprintf@.c \
	sqrt.c \
	srand.c \
	sscanf.c \
	@@ssfind.c \
	@@ssfree.c \
	@@ssib.c \
	@@ssinst.c \
	@@ssnew.c \
	@@ssrem.c \
	@@ssremn.c \
	@@start.c \
	@@stderr.c \
	@@stdin.c \
	@@stdout.c \
	@@steplb.c \
	strcat.c \
	strchr.c \
	strcmp.c \
	strcoll.c \
	strcpy.c \
	strcpyp.c \
	strcspn.c \
	strdup.c \
	strerror.c \
	strftime.c \
	stricmp.c \
	strlen.c \
	strncat.c \
	strncmp.c \
	strncmpi.c \
	strncpy.c \
	strpbrk.c \
	strrchr.c \
	strspn.c \
	strstr.c \
	strtod.c \
	strtok.c \
	strtol.c \
	strtoul.c \
	strxfrm.c \
	@@stymd.c \
	@@sudo.c \
	@@sukydo.c \
	@@super.c \
	svcmain.c \
	@@svfmap.c \
	@@svfree.c \
	@@svnew.c \
	@@svset.c \
	system.c \
	tan.c \
	tanh.c \
	time.c \
	@@tiot.c \
	@@tminit.c \
	tmpfile.c \
	tmpnam.c \
	@@tmrecb.c \
	@@tmrece.c \
	@@tmreck.c \
	@@tmrfue.c \
	@@tmrfuk.c \
	@@tmrfun.c \
	@@tmrget.c \
	@@tmrid.c \
	@@tmsecs.c \
	@@tmstop.c \
	@@tmstrt.c \
	@@tmthrd.c \
	@@tolow.c \
	tolower.c \
	@@toup.c \
	toupper.c \
	@@tqedis.c \
	@@tqeena.c \
	@@tqeget.c \
	@@tqeprg.c \
	@@tqerst.c \
	@@tqnew.c \
	@@@try.c \
	@@try.c \
	@@txbfal.c \
	@@txbfte.c \
	@@txbksz.c \
	@@txblk.c \
	@@txbufl.c \
	@@txbufn.c \
	@@txbufo.c \
	@@txcat.c \
	@@txclos.c \
	@@txcopy.c \
	@@txcyl.c \
	@@txddn.c \
	@@txdel.c \
	@@txden.c \
	@@txdest.c \
	@@txdir.c \
	@@txdmy.c \
	@@txdsn.c \
	@@txerop.c \
	@@txexpd.c \
	@@txfcb.c \
	@@txform.c \
	@@txhold.c \
	@@txinpu.c \
	@@txkeep.c \
	@@txkeyl.c \
	@@txlabe.c \
	@@txlmct.c \
	@@txlrec.c \
	@@txmod.c \
	@@txncp.c \
	@@txnew.c \
	@@txold.c \
	@@txorg.c \
	@@txoutp.c \
	@@txpara.c \
	@@txperm.c \
	@@txpgm.c \
	@@txpriv.c \
	@@txprot.c \
	@@txrddn.c \
	@@txrecf.c \
	@@txretp.c \
	@@txrlse.c \
	@@txrnd.c \
	@@txseq.c \
	@@txshr.c \
	@@txspac.c \
	@@txsyso.c \
	@@txterm.c \
	@@txtrk.c \
	@@txtrtc.c \
	@@txucat.c \
	@@txucs.c \
	@@txunal.c \
	@@txunct.c \
	@@txunit.c \
	@@txvlct.c \
	@@txvols.c \
	@@txvseq.c \
	@@tzget.c \
	@@tzset.c \
	tzset.c \
	@@uastep.c \
	@@uatask.c \
	@@udec.c \
	@@uinc.c \
	ungetc.c \
	unsetenv.c \
	@@userex.c \
	usleep.c \
	vfprintf.c \
	@@vscinv.c \
	vscinv.c \
	vsclear.c \
	@@vsclos.c \
	vsclose.c \
	@@vsclr.c \
	@@vsdel.c \
	vsdelete.c \
	@@vseof.c \
	vseof.c \
	@@vserr.c \
	vserror.c \
	@@vslrec.c \
	vslrecl.c \
	@@vsmdfy.c \
	vsnprint.c \
	vsnprtf@.c \
	@@vsopen.c \
	vsopen.c \
	vsprintf.c \
	vsprtf@.c \
	@@vsread.c \
	vsread.c \
	@@vsshwc.c \
	@@vssteq.c \
	vssteq.c \
	@@vsstge.c \
	vsstge.c \
	@@vstell.c \
	vstell.c \
	vsupdate.c \
	@@vsupdt.c \
	@@vswrit.c \
	vswrite.c \
	@@vsxeof.c \
	@@vsxerr.c \
	vvprintf.c \
	vvscanf.c \
	vwtof.c \
	vwtorf.c \
	wcstombs.c \
	wctomb.c \
	@@wsaget.c \
	wto.c \
	wtodump.c \
	wtodumpf.c \
	wtof.c \
	wtoline.c \
	wtor.c \
	wtorf.c \
	@@wtotb.c \
	@@xmpost.c \
	@@ymdts.c \
	@@ytd.c \
	@@64add.c \
	@@64ai32.c \
	@@64au32.c \
	@@64au64.c \
	@@64and.c \
	@@64ni32.c \
	@@64nu32.c \
	@@64nu64.c \
	@@64cmp.c \
	@@64ci32.c \
	@@64cu32.c \
	@@64cu64.c \
	@@64copy.c \
	@@64dec.c \
	@@64div.c \
	@@64di32.c \
	@@64du32.c \
	@@64du64.c \
	@@64dmod.c \
	@@64vi32.c \
	@@64vu32.c \
	@@64vu64.c \
	@@64fi32.c \
	@@64fu32.c \
	@@64fu64.c \
	@@64fstr.c \
	@@64init.c \
	@@64inc.c \
	@@64is0.c \
	@@64isqr.c \
	@@64lsh1.c \
	@@64lshw.c \
	@@64mod.c \
	@@64qi32.c \
	@@64qu32.c \
	@@64qu64.c \
	@@64mul.c \
	@@64mi32.c \
	@@64mu32.c \
	@@64mu64.c \
	@@64or.c \
	@@64oi32.c \
	@@64ou32.c \
	@@64ou64.c \
	@@64pow.c \
	@@64rsh1.c \
	@@64lsft.c \
	@@64rsft.c \
	@@64rshw.c \
	@@64sub.c \
	@@64si32.c \
	@@64su32.c \
	@@64su64.c \
	@@64tstr.c \
	@@64ti32.c \
	@@64tu32.c \
	@@64tu64.c \
	@@64xor.c \
	@@64xi32.c \
	@@64xu32.c \
	@@64xu64.c \
	@@64test.c \
	testlstv.c \
	tsocmd.c \
	tsocmdf.c \
	@@ispexe.c \
	@@isplnk.c \
	@@ispsel.c \
    @@gtdsab.c \
    @@nxdsab.c \
    @@listal.c \
    testdsab.c \
    @@txacat.c \
    @@txadel.c \
    @@txakee.c \
    @@txauca.c \
    @@dsalc.c \
    @@dsalcf.c \
    @@dsfree.c \
    @@freeal.c

# depricated:
#	clib.c \
#	cliblock.c \
#	@@ctx.c \
#	memset.c \
#	stdio.c \
#	stdlib.c \
#	string.c \

# non-generated .asm assembler source files 
A_FILES := 

# generated .s assembler source files (one for each source file)
S_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.s))

# object files (one for each .c and .asm source file)
O_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.o)) \
           $(foreach filename,$(A_FILES),$(filename:.asm=.o))

# export MACn variables for mvsasm->jobasm script
export MAC1=FIX0MIG.CRENT370.MACLIB
export MAC2=SYS1.HASPSRC

# export dataset names used by mvsasm script
export MVSASM_PUNCH=FIX0MIG.CRENT370.OBJECT
export MVSASM_SYSLMOD=FIX0MIG.CRENT370.NCALIB

all: $(S_FILES) $(O_FILES)
	@echo "Done"
# Note: PHONY is important here. Without it, implicit rules will try
#       to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# build object files from the generated assembler files (.s)
%.o: %.s
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

# build object files from assembler files (.asm)
%.o: %.asm
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

# compile C source files (.c) into assembler files (.s)
%.s: %.c
	@echo "Compile $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

# remove generated files
clean:
	@rm -f $(S_FILES) $(O_FILES)

