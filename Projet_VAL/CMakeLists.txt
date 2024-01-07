# CMakeList.txt : projet CMake pour Projet_VAL, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Projet_VAL  "rame.hpp" "rame.cpp" "Val.cpp" "station.cpp" "station.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Projet_VAL PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
