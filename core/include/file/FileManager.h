#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <optional>

namespace TextEditor {
namespace File {

class FileManager {
public:
    FileManager() = default;
    ~FileManager() = default;

    // Create: Create a new file with content
    bool createFile(const std::string& filepath, const std::string& content = "");

    // Read: Read entire file content
    std::optional<std::string> readFile(const std::string& filepath);

    // Update: Update/overwrite file content
    bool updateFile(const std::string& filepath, const std::string& content);

    // Delete: Delete a file
    bool deleteFile(const std::string& filepath);

    // Utility methods
    bool fileExists(const std::string& filepath);
    std::optional<std::vector<std::string>> readLines(const std::string& filepath);
    bool appendToFile(const std::string& filepath, const std::string& content);

private:
    std::string getErrorMessage() const;
    std::string m_lastError;
};

} // namespace File
} // namespace TextEditor

#endif // FILEMANAGER_H
