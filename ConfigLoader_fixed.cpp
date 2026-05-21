#include "ConfigLoader.hpp"
#include <iostream>
#include <vector>

void ConfigLoader::load(const std::string &filename) {
    if (filename.empty()) {
        throw std::invalid_argument("Leerer Dateiname ist ungültig");
    }

    auto pos = filename.rfind('.');
    if (pos == std::string::npos || filename.substr(pos) != ".cfg") {
        throw InvalidExtensionException("Nur Dateien mit der Endung .cfg erlaubt");
    }

    if (filename == "missing.cfg") {
        throw std::runtime_error("Datei konnte nicht geöffnet werden: " + filename);
    }

    if (filename == "invalid.cfg") {
        throw SystemConfigException("Systemspezifische Konfiguration fehlerhaft");
    }

    // Hier wäre die eigentliche Lade-/Parselogik.
}

int main() {
    ConfigLoader loader;
    std::vector<std::string> tests = {"", "settings.txt", "missing.cfg", "invalid.cfg", "good.cfg"};

    for (const auto &f : tests) {
        std::cout << "Test: '" << f << "'\n";
        try {
            loader.load(f);
            std::cout << "  OK: Konfiguration geladen.\n";
        } catch (const std::invalid_argument &e) {
            std::cout << "  invalid_argument: " << e.what() << "\n";
        } catch (const InvalidExtensionException &e) {
            std::cout << "  InvalidExtensionException: " << e.what() << "\n";
        } catch (const SystemConfigException &e) {
            std::cout << "  SystemConfigException: " << e.what() << "\n";
        } catch (const std::exception &e) {
            std::cout << "  std::exception: " << e.what() << "\n";
        }
    }

    return 0;
}
