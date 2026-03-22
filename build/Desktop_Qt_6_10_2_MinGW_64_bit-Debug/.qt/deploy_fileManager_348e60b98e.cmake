include("D:/FileAPP/fileManager/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/fileManager-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/FileAPP/fileManager/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/fileManager.exe"
    GENERATE_QT_CONF
)
