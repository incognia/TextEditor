#include "file/FileManager.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstring>

namespace TextEditor {
namespace File {

bool FileManager::createFile(const std::string& filepath, const std::string& content) {
    if (fileExists(filepath)) {
        m_lastError = "File already exists: " + filepath;
        return false;
    }

    std::ofstream file(filepath);
    if (!file.is_open()) {
        m_lastError = "Failed to create file: " + filepath;
        return false;
    }

    if (!content.empty()) {
        file << content;
    }

    file.close();
    return true;
}

std::optional<std::string> FileManager::readFile(const std::string& filepath) {
    if (!fileExists(filepath)) {
        m_lastError = "File does not exist: " + filepath;
        return std::nullopt;
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        m_lastError = "Failed to open file: " + filepath;
        return std::nullopt;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

bool FileManager::updateFile(const std::string& filepath, const std::string& content) {
    if (!fileExists(filepath)) {
        m_lastError = "File does not exist: " + filepath;
        return false;
    }

    std::ofstream file(filepath, std::ios::trunc);
    if (!file.is_open()) {
        m_lastError = "Failed to open file for writing: " + filepath;
        return false;
    }

    file << content;
    file.close();
    return true;
}

bool FileManager::deleteFile(const std::string& filepath) {
    if (!fileExists(filepath)) {
        m_lastError = "File does not exist: " + filepath;
        return false;
    }

    try {
        std::filesystem::remove(filepath);
        return true;
    } catch (const std::filesystem::filesystem_error& e) {
        m_lastError = "Failed to delete file: " + std::string(e.what());
        return false;
    }
}

bool FileManager::fileExists(const std::string& filepath) {
    return std::filesystem::exists(filepath);
}

std::optional<std::vector<std::string>> FileManager::readLines(const std::string& filepath) {
    if (!fileExists(filepath)) {
        m_lastError = "File does not exist: " + filepath;
        return std::nullopt;
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        m_lastError = "Failed to open file: " + filepath;
        return std::nullopt;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

bool FileManager::appendToFile(const std::string& filepath, const std::string& content) {
    if (!fileExists(filepath)) {
        m_lastError = "File does not exist: " + filepath;
        return false;
    }

    std::ofstream file(filepath, std::ios::app);
    if (!file.is_open()) {
        m_lastError = "Failed to open file for appending: " + filepath;
        return false;
    }

    file << content;
    file.close();
    return true;
}

std::string FileManager::getErrorMessage() const {
    return m_lastError;
}

} // namespace File
} // namespace TextEditor
