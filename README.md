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

Have a look at `test/main.c`

```bash
$ gcc -L/usr/local/lib/tiny_event_trace -ltiny_event_trace test/another.c test/main.c -o test.out
```
