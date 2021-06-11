# tiny-event-trace
Profile your C code with chrome://tracing

## Get started
### Build

```bash
$ mkdir -p build
$ cd build
$ cmake ..
$ make
```

### Install

```bash
$ make install
```

### Uninstall

```bash
$ cat install_manifest.txt | xargs rm
```

### Trace event

Like `test/main.c`
