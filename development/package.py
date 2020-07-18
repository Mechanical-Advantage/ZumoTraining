import os
import shutil

exclude = ["development", "resources", "README.md"]
projects = [x for x in os.listdir() if x[0] != "." and x not in exclude]

os.mkdir("temp")
for project in projects:
    # Create temp directory structure
    os.mkdir(os.path.join("temp", project))
    os.mkdir(os.path.join("temp", project, "build"))
    os.mkdir(os.path.join("temp", project, ".vscode"))

    # Add "arduino.json" with custom path
    arduino_config = open(os.path.join(
        "development", "vscode", "arduino.json"), "r").read()
    arduino_config = arduino_config.replace("${name}", project)
    open(os.path.join("temp", project, ".vscode",
                      "arduino.json"), "w").write(arduino_config)

    # Add extra config files
    shutil.copy(os.path.join("development", "vscode", "c_cpp_properties.json"),
                os.path.join("temp", project, ".vscode", "c_cpp_properties.json"))
    shutil.copy(os.path.join("development", "vscode", "settings.json"),
                os.path.join("temp", project, ".vscode", "settings.json"))

    # Copy src files
    src_files = [x for x in os.listdir(
        os.path.join(project, "src")) if x[0] != "."]
    for src_file in src_files:
        shutil.copy(os.path.join(project, "src", src_file),
                    os.path.join("temp", project, src_file))

    # Create archive
    shutil.make_archive(os.path.join(project, project),
                        "zip", os.path.join("temp", project))
    shutil.rmtree(os.path.join("temp", project))

# Remove temp directory
shutil.rmtree("temp")
