#include "emfilei.h"

void emfile_dump(EMFILE *f)
{
	unsigned	flag	= f->flags;
	unsigned	type	= flag & EMFILE_FLAG_UPDATE;
	unsigned	count;
	unsigned	n;
	
	wtof("%s: enter", __func__);

	if (!f) goto quit;

	wtof("--------------------------------------------------");
	wtof("   emfile handle : 0x%08X", f);
	wtof("     eye catcher : %.8s", f->eye);
	wtof("     alloc bytes : %llu", f->alloc);
	wtof("      used bytes : %llu", f->used);
	wtof("    offset bytes : %llu", f->offset);
	wtof("   current block : %u", f->block);
	wtof("    total blocks : %u", f->blocks);
	wtof("    total tracks : %u", f->tracks);
	wtof("blocks per track : %u", f->blkstrk);
	wtof("      block size : %u", f->blksize);
    wtof("        BDAM DCB : 0x%08X", f->bdamdcb);
    wtof("       BDAM DECB : 0x%08X", f->bdamdecb);
    wtof("  buffer address : 0x%08X", f->buf);
    wtof("   header buffer : 0x%08X", f->r0);
    if (f->r0) {
		EMFILE10 *hdr = (EMFILE10 *)f->r0;

		wtof("                 : eye catcher %s", hdr->eye);
		wtof("                 : created     %s", ctime64(&hdr->create));
		wtof("                 : modified    %s", ctime64(&hdr->modified));
		wtof("                 : file size   %llu", hdr->size);
	}
    wtof("          ddname : %s", f->ddname);
    wtof("          dsname : %s", f->dsname);
	wtof("           flags : 0x%04X", f->flags);
	if (flag & EMFILE_FLAG_MULTIV) {
		wtof("                 : MULTIV  (multiple volumes)");
	}
	if (flag & EMFILE_FLAG_FULL) {
		wtof("                 : FULL    (full initialization)");
	}
	if (flag & EMFILE_FLAG_GROW) {
		wtof("                 : GROW    (grow dataset possible)");
	}
	
	if (type == EMFILE_FLAG_UPDATE) {
		wtof("                 : UPDATE  (READ + WRITE)");
	}
	else if (type == EMFILE_FLAG_READ) {
		wtof("                 : READ ONLY");
	}
	else if (type == EMFILE_FLAG_WRITE) {
		wtof("                 : WRITE ONLY");
	}
	
	if (flag & EMFILE_FLAG_APPEND) {
		wtof("                 : APPEND  (seek to EOF at open)");
	}
	if (flag & EMFILE_FLAG_CREATE) {
		wtof("                 : CREATE  (create if not exist)");
	}
	if (flag & EMFILE_FLAG_DYNAMIC) {
		wtof("                 : DYNAMIC (allocated via SVC 99)");
	}
	if (flag & EMFILE_FLAG_NEW) {
		wtof("                 : NEW     (dataset was created)");
	}
	if (flag & EMFILE_FLAG_EOF) {
		wtof("                 : EOF     (end of file)");
	}
	if (flag & EMFILE_FLAG_DIRTY) {
		wtof("                 : DIRTY   (buffer has unwritten data)");
	}
	count = array_count(&f->volser);
	wtof("         volumes : %u", count);
	for(n=1; n <= count; n++) {
		char *vol = array_get(&f->volser, n);
		wtof("                 : %s", vol);
	}
    wtof("      last error : %d", f->error);
    wtof("     grow ddname : %s", f->growdd);
    wtof("         devtype : 0x%02X", f->devtype);
	wtof("--------------------------------------------------");

quit:
	wtof("%s: exit", __func__);
}
