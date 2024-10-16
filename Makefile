# The name of the binary to be created.
TARGET = HauntedGraveyard
# The type of the binary to be created - ps-exe is most common.
TYPE = ps-exe

# The list of sources files to compile within the binary.
SRCS = \
core/Area.cpp \
system/Sound.cpp \
system/SimpleCDAudio.cpp \
graphics/Render2D.cpp \
graphics/Camera2D.cpp \
graphics/Sprite.cpp \
graphics/TexturePage.cpp \
graphics/BigSprite.cpp \
graphics/Pixel.cpp \
graphics/TileMap.cpp \
graphics/UI/RenderUI.cpp \
graphics/UI/Button.cpp \
graphics/UI/Image.cpp \
graphics/UI/TextBox.cpp \
GraveKeeper.cpp \
Player.cpp \
JackOLantern.cpp \
SplashScene.cpp \
TitleScene.cpp \
LevelScene.cpp \
Level1EntranceScene.cpp \
PointDemoScene.cpp \
Level2GraveyardScene.cpp \
GameApp.cpp \
main.cpp

ifeq ($(NO_CD), true)
CPPFLAGS += -DNO_CD
endif

# This will activate the PSYQo library and the rest of the toolchain.
include third_party/nugget/psyqo/psyqo.mk
