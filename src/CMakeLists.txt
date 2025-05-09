add_definitions(-DTRANSLATION_DOMAIN=\"quebecinondation.github.com\")

add_library(quebecinondation.github.com MODULE quebecinondation.cpp
                      package/contents/images/pairs.svg package/contents/ui/main.qml package/metadata.json quebecinondation.cpp quebecinondation.h)

target_link_libraries(quebecinondation.github.com
                      Qt6::Gui
                      Qt6::Network
                      Plasma::Plasma
                      KF6::I18n)


install(TARGETS quebecinondation.github.com DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/applets)

plasma_install_package(package quebecinondation.github.com)
