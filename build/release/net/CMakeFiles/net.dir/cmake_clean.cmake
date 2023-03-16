file(REMOVE_RECURSE
  "../lib/libnet.pdb"
  "../lib/libnet.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/net.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
