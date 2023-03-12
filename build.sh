echo "Starting Building"
d=$(date +%s)
if [ -d build ]; then
    cd build
else
    mkdir build
    cd build
fi

if cmake -G "MinGW Makefiles" .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=c:/msys64/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=c:/msys64/mingw64/bin/g++.exe; then
    echo "CMake Successful"

    if cmake --build .; then
        echo "make Successful"
        echo "Build took $(($(date +%s)-d)) seconds."
    else
        echo "make Failed"
        sleep 5
    fi
else
    echo "CMake Failed"
    sleep 5
fi
cd ..
