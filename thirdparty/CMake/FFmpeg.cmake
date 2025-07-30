include(ExternalProject)

ExternalProject_Add(FFmpeg
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/ffmpeg-src
  CONFIGURE_COMMAND ./configure --prefix=${CMAKE_BINARY_DIR}/_install/ffmpeg
                                --disable-static
                                --enable-shared
                                --disable-doc
                                --disable-programs
  BUILD_COMMAND make -j$(nproc)
  INSTALL_COMMAND make install
  BUILD_IN_SOURCE 1
)
