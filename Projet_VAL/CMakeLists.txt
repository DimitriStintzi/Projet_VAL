# CMakeList.txt : projet CMake pour Projet_VAL, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Projet_VAL "Projet_VAL.cpp" "rame.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Projet_VAL PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
