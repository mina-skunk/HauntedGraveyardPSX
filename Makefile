# The name of the binary to be created.
TARGET = HauntedGraveyard
# The type of the binary to be created - ps-exe is most common.
TYPE = ps-exe

# The list of sources files to compile within the binary.
SRCS = \
system/Sound.cpp \
system/SimpleCDAudio.cpp \
graphics/Render2D.cpp \
graphics/Camera2D.cpp \
graphics/Sprite.cpp \
graphics/TexturePage.cpp \
graphics/UI/RenderUI.cpp \
graphics/UI/Button.cpp \
graphics/UI/Image.cpp \
graphics/UI/TextBox.cpp \
Player.cpp \
SplashScene.cpp \
TitleScene.cpp \
Level1EntranceScene.cpp \
GameApp.cpp \
main.cpp

# Setting the minimum version of the C++. C++-20 is the minimum required version by PSYQo.
CXXFLAGS = -std=c++20 

# CFLAGS = -DNO_CD

# This will activate the PSYQo library and the rest of the toolchain.
include third_party/nugget/psyqo/psyqo.mk
