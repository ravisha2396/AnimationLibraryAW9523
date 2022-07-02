set(SOURCES main.c
            AW9523/AW9523.c LEDDriver/leddriver.c)

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS . ../include/AW9523 ../include/LEDDriver)
