in order to run the program, enter the commands:

cd ~/projects/SensorProject/build

cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake

cmake --build .

./sensor_app 
or for the tests:
ctest --output-on-failure

