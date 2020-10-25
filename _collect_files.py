import glob

all_cpp_files = glob.glob("src/modules/*.cpp")
print(" ".join(all_cpp_files).replace("\\", "/"))