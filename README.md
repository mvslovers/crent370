# CRENT370

A reentrant C runtime library for MVS 3.8j (TK4-, TK5, CE).

Originally created by Michael Dean Rayborn, now maintained by the
[mvslovers](https://github.com/mvslovers) community.

## Prerequisites

- `gccmvs` cross-compiler (GCC targeting MVS/370 assembler)
- `curl` and `jq`
- MVS system with [mvs/MF](https://github.com/mvslovers/mvsmf) (z/OSMF REST API)

## MVS Dataset Setup

Before building, three partitioned datasets must be allocated on the
target MVS system.  Replace `<HLQ>` with your high-level qualifier
in `config.mk`:

| Dataset                    | RECFM | LRECL | Purpose                        |
|----------------------------|-------|-------|--------------------------------|
| `<HLQ>.CRENT370.MACLIB`    | FB    | 80    | Macro and copy member library  |
| `<HLQ>.CRENT370.OBJECT`    | FB    | 80    | Assembled object decks (punch) |
| `<HLQ>.CRENT370.NCALIB`    | U     | 0     | Link-edited load modules       |

After allocating the datasets, upload all macro and copy members from
the `maclib/` directory in this repository into `<HLQ>.CRENT370.MACLIB`:

```bash
for f in maclib/*; do
  member=$(basename "${f%.*}" | tr 'a-z' 'A-Z')
  curl -s -X PUT \
    -u "<USERNAME>:<PASSWORD>" \
    -H "Content-Type: text/plain" \
    -H "X-IBM-Data-Type: text" \
    --data-binary @"$f" \
    "http://<HOST>:<PORT>/zosmf/restfiles/ds/<HLQ>.CRENT370.MACLIB(${member})"
done
```

## MVS Connection

Copy `.env.example` to `.env` and set your MVS host credentials:

```bash
cp .env.example .env
# edit .env with your values
```

```bash
MVSASM_HOST=your-mvs-host
MVSASM_PORT=1080
MVSASM_USER=IBMUSER
MVSASM_PASS=secret
```

The `.env` file is git-ignored and never committed.

## Configuration

Edit `config.mk` to match your environment:

```makefile
export MAC1           := <HLQ>.CRENT370.MACLIB
export MAC2           := SYS2.MACLIB
export MVSASM_PUNCH   := <HLQ>.CRENT370.OBJECT
export MVSASM_SYSLMOD := <HLQ>.CRENT370.NCALIB
```

## Building

```
# Build all modules
make

# Build a single module
make -C src/jes

# Clean all generated files
make clean
```

## Project Structure

```
asm/          Assembler-only modules
src/clib/     C runtime library (libc functions)
src/cmtt/     Console message translation table
src/dyn75/    SVC 75 dynamic allocation / TCP-IP socket layer
src/jes/      JES2 spool interface
src/racf/     RACF security interface
src/thdmgr/   Thread manager
src/time64/   64-bit time functions
maclib/       Assembler macros and copy members
include/      C header files
jcl/          Sample JCL
```

## License

BSD 2-Clause -- see [LICENSE](LICENSE) for details.
