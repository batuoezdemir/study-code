#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class ConfigLoader 
{
public:
    void load(const string &filename)
    {
        if (filename.empty())
        {
            throw invalid_argument("Fehler: Dateiname darf nicht leer sein.");
        }
        if
    }
};
int main()
{

}
















#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Eigene Exception für fehlerhafte Konfiguration
class InvalidConfigException : public runtime_error {
public:
    InvalidConfigException(const string& message)
        : runtime_error(message) {}
};

class ConfigLoader {
public:
    void load(const string& filename) {

        // 1. Leerer Dateiname
        if (filename.empty()) {
            throw invalid_argument("Fehler: Dateiname darf nicht leer sein.");
        }

        // 2. Nur .cfg erlaubt
        if (filename.size() < 4 ||
            filename.substr(filename.size() - 4) != ".cfg") {
            throw invalid_argument("Fehler: Nur Dateien mit Endung '.cfg' sind erlaubt.");
        }

        // 3. Datei kann nicht geöffnet werden
        if (filename == "missing.cfg") {
            throw runtime_error("Fehler: Datei konnte nicht geöffnet werden.");
        }

        // 4. Fehlerhafte Konfiguration
        if (filename == "invalid.cfg") {
            throw InvalidConfigException(
                "Fehler: Systemspezifische Konfiguration ist fehlerhaft."
            );
        }

        // Erfolgsfall
        cout << "Datei '" << filename << "' erfolgreich geladen.\n";
    }
};

int main() {

    ConfigLoader loader;

    string testFiles[] = {
        "",
        "config.txt",
        "missing.cfg",
        "invalid.cfg",
        "system.cfg"
    };

    for (const auto& file : testFiles) {

        cout << "\nTeste Datei: \"" << file << "\"\n";

        try {
            loader.load(file);
        }
        catch (const InvalidConfigException& e) {
            cout << "InvalidConfigException gefangen: " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "invalid_argument gefangen: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "runtime_error gefangen: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Allgemeine Exception gefangen: " << e.what() << endl;
        }
    }

    return 0;
}