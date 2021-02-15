[![Build Status](https://travis-ci.org/maximilianvoss/chttp.svg?branch=master)](https://travis-ci.org/maximilianvoss/chttp)

# CHTTP

CHTTP is a small library which wraps libcurl with some convenience methods.

## Dependencies

```bash
(git clone https://github.com/maximilianvoss/clogger.git && cd clogger && cmake -G "Unix Makefiles" && make && sudo make install)
```

## Building

... with -fPIC enabled, use:

```bash
cmake -G "Unix Makefiles"
make 
sudo make install 
```

... with -fPIC disabled, use:

```bash
cmake -Dnofpic=1 -G "Unix Makefiles"
make 
sudo make install 
```