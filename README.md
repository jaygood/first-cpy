python3 setup.py build_ext --inplace

https://stackoverflow.com/questions/28571611/boost-python-hello-world-on-mac-os-x
https://github.com/flipdazed/boost-python-hello-world

I had to
cp boost-python3/lib/libboost_python-mt.dylib boost-python/lib/

mv libboost_python-mt.a libboost_python2-mt.a && cp libboost_python3-mt.a libboost_python-mt.a
mv libboost_python-mt.dylib libboost_python2-mt.dylib && cp libboost_python3-mt.dylib libboost_python-mt.dylib
mv libboost_python.a libboost_python2.a && cp libboost_python3.a libboost_python.a
mv libboost_python.dylib libboost_python2.dylib && cp libboost_python3-mt.dylib libboost_python.dylib