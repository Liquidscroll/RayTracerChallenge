add_test( [==[Tuple of point]==] D:/code/RayTracerChallenge/build/main.exe [==[Tuple of point]==]  )
set_tests_properties( [==[Tuple of point]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Tuple of Vector]==] D:/code/RayTracerChallenge/build/main.exe [==[Tuple of Vector]==]  )
set_tests_properties( [==[Tuple of Vector]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( Addition D:/code/RayTracerChallenge/build/main.exe Addition  )
set_tests_properties( Addition PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Subtracting 2 points]==] D:/code/RayTracerChallenge/build/main.exe [==[Subtracting 2 points]==]  )
set_tests_properties( [==[Subtracting 2 points]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Subtract a vector from a point]==] D:/code/RayTracerChallenge/build/main.exe [==[Subtract a vector from a point]==]  )
set_tests_properties( [==[Subtract a vector from a point]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Subtract 2 vectors]==] D:/code/RayTracerChallenge/build/main.exe [==[Subtract 2 vectors]==]  )
set_tests_properties( [==[Subtract 2 vectors]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Subtract a vector from the 0 vector]==] D:/code/RayTracerChallenge/build/main.exe [==[Subtract a vector from the 0 vector]==]  )
set_tests_properties( [==[Subtract a vector from the 0 vector]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Tuple negation]==] D:/code/RayTracerChallenge/build/main.exe [==[Tuple negation]==]  )
set_tests_properties( [==[Tuple negation]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Multiply by scalar]==] D:/code/RayTracerChallenge/build/main.exe [==[Multiply by scalar]==]  )
set_tests_properties( [==[Multiply by scalar]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Multiply by fractional scalar]==] D:/code/RayTracerChallenge/build/main.exe [==[Multiply by fractional scalar]==]  )
set_tests_properties( [==[Multiply by fractional scalar]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Divide tuple by scalar]==] D:/code/RayTracerChallenge/build/main.exe [==[Divide tuple by scalar]==]  )
set_tests_properties( [==[Divide tuple by scalar]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Get Magnitude of Vector]==] D:/code/RayTracerChallenge/build/main.exe [==[Get Magnitude of Vector]==]  )
set_tests_properties( [==[Get Magnitude of Vector]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Normalizing Vectors]==] D:/code/RayTracerChallenge/build/main.exe [==[Normalizing Vectors]==]  )
set_tests_properties( [==[Normalizing Vectors]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Dot Product]==] D:/code/RayTracerChallenge/build/main.exe [==[Dot Product]==]  )
set_tests_properties( [==[Dot Product]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( Cross_Product D:/code/RayTracerChallenge/build/main.exe Cross_Product  )
set_tests_properties( Cross_Product PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Basic Colours]==] D:/code/RayTracerChallenge/build/main.exe [==[Basic Colours]==]  )
set_tests_properties( [==[Basic Colours]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Add/Subtract/Multiply Colors]==] D:/code/RayTracerChallenge/build/main.exe [==[Add/Subtract/Multiply Colors]==]  )
set_tests_properties( [==[Add/Subtract/Multiply Colors]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Create Canvas]==] D:/code/RayTracerChallenge/build/main.exe [==[Create Canvas]==]  )
set_tests_properties( [==[Create Canvas]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Write Pixel]==] D:/code/RayTracerChallenge/build/main.exe [==[Write Pixel]==]  )
set_tests_properties( [==[Write Pixel]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
add_test( [==[Hello World!]==] D:/code/RayTracerChallenge/build/main.exe [==[Hello World!]==]  )
set_tests_properties( [==[Hello World!]==] PROPERTIES WORKING_DIRECTORY D:/code/RayTracerChallenge/build)
set( main_TESTS [==[Tuple of point]==] [==[Tuple of Vector]==] Addition [==[Subtracting 2 points]==] [==[Subtract a vector from a point]==] [==[Subtract 2 vectors]==] [==[Subtract a vector from the 0 vector]==] [==[Tuple negation]==] [==[Multiply by scalar]==] [==[Multiply by fractional scalar]==] [==[Divide tuple by scalar]==] [==[Get Magnitude of Vector]==] [==[Normalizing Vectors]==] [==[Dot Product]==] Cross_Product [==[Basic Colours]==] [==[Add/Subtract/Multiply Colors]==] [==[Create Canvas]==] [==[Write Pixel]==] [==[Hello World!]==])