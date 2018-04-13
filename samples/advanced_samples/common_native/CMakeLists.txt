set(SRC
	src/Shader.cpp
	src/Text.cpp
	src/Texture.cpp
	src/ETCHeader.cpp
	src/Matrix.cpp
	src/Timer.cpp)

if(ANDROID)
	set(SRC ${SRC}
		src/JavaClass.cpp
		src/AndroidPlatform.cpp)
else()
	set(SRC ${SRC}
		src/EGLRuntime.cpp
		src/Platform.cpp)
endif()
add_library(common-native STATIC ${SRC})

target_include_directories(common-native PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/inc/mali)

target_compile_definitions(common-native PUBLIC GLES_VERSION=2)
target_link_libraries(common-native GLESv2 EGL)
if(ANDROID)
	target_link_libraries(common-native log)
else()
	target_link_libraries(common-native X11)
endif()

add_library(common-native-gles3 STATIC ${SRC})

target_include_directories(common-native-gles3 PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/inc/mali)

target_compile_definitions(common-native-gles3 PUBLIC GLES_VERSION=3)
target_link_libraries(common-native-gles3 GLESv3 EGL)
if(ANDROID)
	target_link_libraries(common-native-gles3 log)
else()
	target_link_libraries(common-native-gles3 X11)
endif()
