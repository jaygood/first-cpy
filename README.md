```bash
python3 setup.py build_ext --inplace
```
I had to
```bash
sudo cp /usr/local/opt/boost-python3/lib/libboost_python3-mt.dylib /usr/local/opt/boost-python/lib/libboost_python-mt.dylib
```

* https://stackoverflow.com/questions/28571611/boost-python-hello-world-on-mac-os-x
* https://github.com/flipdazed/boost-python-hello-world
* https://github.com/davisking/dlib/issues/889
