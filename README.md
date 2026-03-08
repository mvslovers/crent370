# CRENT370

A reentrant C runtime library for MVS 3.8j (TK4-, TK5, CE).

Originally created by Michael Dean Rayborn, now maintained by the
[mvslovers](https://github.com/mvslovers) community.

## Prerequisites

- [c2asm370](https://github.com/mvslovers/c2asm370) cross-compiler
- Python 3.12+
- MVS system with [mvs/MF](https://github.com/mvslovers/mvsmf) (z/OSMF-compatible REST API)

## Setup

Copy `.env.example` to `.env` and set your MVS connection details:

```bash
cp .env.example .env
# edit .env with your values
```

Then bootstrap the project (allocates datasets on MVS, uploads maclib):

```bash
make bootstrap
```

## Building

```bash
# Build all modules (cross-compile + assemble + NCAL link)
make build

# Build a single module
make build ARGS="--member HELLO"

# Clean local build artifacts
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
