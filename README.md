# TextEditor

A simple, fast, and lightweight multiplatform text and Markdown editor built with native technologies for optimal performance and user experience on each operating system.

## Overview

TextEditor is designed to provide a consistent editing experience across all major desktop platforms while leveraging native frameworks and languages for the best performance and integration with each operating system.

### Platform-Specific Implementations

- **Windows**: C# with WPF/WinUI for native Windows experience
- **macOS**: Swift with SwiftUI/AppKit for seamless macOS integration  
- **Linux (GNOME)**: C++ with GTK4 for modern GNOME desktop integration
- **Linux (KDE Plasma)**: C++ with Qt6 for native Plasma experience

## Features

### Core Functionality
- [x] Plain text editing with syntax highlighting
- [x] Markdown editing with live preview
- [x] Multiple tabs support
- [x] Find and replace functionality
- [x] Auto-save and session restoration
- [x] Customizable themes (dark/light mode)

### Markdown Support
- [x] CommonMark specification compliance
- [x] GitHub Flavored Markdown (GFM) extensions
- [x] Live preview with synchronized scrolling
- [x] Table editing support
- [x] Mermaid diagrams rendering
- [x] Math expressions (LaTeX/KaTeX)

### Internationalization
- [x] English (en)
- [x] Spanish (es)
- [x] French (fr)
- [x] German (de)
- [ ] More languages (contributions welcome)

## Installation

### Windows
```powershell
# Download from Microsoft Store (recommended)
winget install TextEditor

# Or download .msix installer from releases
# https://github.com/yourusername/TextEditor/releases
```

### macOS
```bash
# Download from Mac App Store (recommended)
# Or install via Homebrew
brew install --cask texteditor

# Or download .dmg from releases
# https://github.com/yourusername/TextEditor/releases
```

### Linux

#### Ubuntu/Debian
```bash
# Download .deb package from releases
sudo dpkg -i texteditor_1.0.0_amd64.deb
sudo apt-get install -f  # Fix dependencies if needed
```

#### Fedora/RHEL
```bash
# Download .rpm package from releases
sudo dnf install texteditor-1.0.0-1.x86_64.rpm
```

#### Arch Linux
```bash
# Install from AUR
yay -S texteditor-git
```

#### Flatpak (Universal)
```bash
flatpak install flathub io.github.yourusername.TextEditor
```

#### AppImage (Portable)
```bash
# Download AppImage from releases
chmod +x TextEditor-1.0.0-x86_64.AppImage
./TextEditor-1.0.0-x86_64.AppImage
```

## Development

### Prerequisites

#### Windows Development
- Visual Studio 2022 (17.8+)
- .NET 8.0 SDK
- Windows 11 SDK

#### macOS Development
- Xcode 15.0+
- Swift 5.9+
- macOS 14.0+ SDK

#### Linux Development
- GCC 11+ or Clang 15+
- CMake 3.25+
- GTK4 development libraries (for GNOME)
- Qt6 development libraries (for KDE Plasma)

### Building from Source

#### Windows
```powershell
git clone https://github.com/yourusername/TextEditor.git
cd TextEditor/src/windows
dotnet restore
dotnet build --configuration Release
```

#### macOS
```bash
git clone https://github.com/yourusername/TextEditor.git
cd TextEditor/src/macos
xcodebuild -scheme TextEditor -configuration Release
```

#### Linux (GTK4/GNOME)
```bash
git clone https://github.com/yourusername/TextEditor.git
cd TextEditor/src/linux/gtk
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

#### Linux (Qt6/KDE)
```bash
git clone https://github.com/yourusername/TextEditor.git
cd TextEditor/src/linux/qt
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## Project Structure

```
TextEditor/
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── docs/
│   ├── user-guide/
│   ├── developer-guide/
│   └── api-reference/
├── src/
│   ├── windows/           # C# WPF/WinUI implementation
│   │   ├── TextEditor.sln
│   │   ├── TextEditor/
│   │   ├── TextEditor.Core/
│   │   └── TextEditor.Tests/
│   ├── macos/            # Swift SwiftUI/AppKit implementation
│   │   ├── TextEditor.xcodeproj
│   │   ├── TextEditor/
│   │   ├── TextEditorCore/
│   │   └── TextEditorTests/
│   └── linux/            # C++ implementations
│       ├── gtk/          # GTK4 for GNOME
│       │   ├── CMakeLists.txt
│       │   ├── src/
│       │   ├── include/
│       │   └── tests/
│       └── qt/           # Qt6 for KDE Plasma
│           ├── CMakeLists.txt
│           ├── src/
│           ├── include/
│           └── tests/
├── shared/
│   ├── localization/     # Translation files
│   │   ├── en.json
│   │   ├── es.json
│   │   ├── fr.json
│   │   └── de.json
│   ├── themes/           # UI themes
│   └── icons/            # Application icons
├── scripts/              # Build and deployment scripts
│   ├── build-windows.ps1
│   ├── build-macos.sh
│   └── build-linux.sh
└── packages/             # Package configurations
    ├── windows/          # MSIX, MSI configurations
    ├── macos/            # DMG, PKG configurations
    └── linux/            # DEB, RPM, AppImage, Flatpak
```

## Configuration

### Settings Location

- **Windows**: `%APPDATA%\TextEditor\settings.json`
- **macOS**: `~/Library/Application Support/TextEditor/settings.json`
- **Linux**: `~/.config/TextEditor/settings.json`

### Default Settings
```json
{
  "theme": "auto",
  "language": "auto",
  "font": {
    "family": "system",
    "size": 14
  },
  "editor": {
    "tabSize": 4,
    "wordWrap": true,
    "showLineNumbers": true,
    "autoSave": true,
    "autoSaveInterval": 30
  },
  "markdown": {
    "enablePreview": true,
    "syncScroll": true,
    "renderMath": true,
    "renderDiagrams": true
  }
}
```

## Contributing

We welcome contributions from the community! Please read our [Contributing Guidelines](CONTRIBUTING.md) for details on:

- Code of Conduct
- Development workflow
- Pull request process
- Coding standards for each platform
- Translation contributions

### Development Setup

1. Fork the repository
2. Clone your fork: `git clone https://github.com/yourusername/TextEditor.git`
3. Create a feature branch: `git checkout -b feature/amazing-feature`
4. Make your changes following the platform-specific coding standards
5. Test your changes thoroughly
6. Commit with conventional commits: `git commit -m "feat: add amazing feature"`
7. Push to your branch: `git push origin feature/amazing-feature`
8. Open a Pull Request

## Roadmap

### Version 1.1 (Q2 2025)
- [ ] Plugin system architecture
- [ ] Advanced search with regex support
- [ ] Git integration
- [ ] Distraction-free writing mode

### Version 1.2 (Q3 2025)
- [ ] Collaborative editing (real-time)
- [ ] Cloud synchronization
- [ ] Advanced theming system
- [ ] Performance optimizations

### Version 2.0 (Q4 2025)
- [ ] AI-powered writing assistance
- [ ] Advanced Markdown extensions
- [ ] Integrated terminal
- [ ] Project management features

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [CommonMark](https://commonmark.org/) for Markdown specification
- [Mermaid](https://mermaid-js.github.io/) for diagram rendering
- [KaTeX](https://katex.org/) for math rendering
- [Highlight.js](https://highlightjs.org/) for syntax highlighting
- Our amazing community of contributors and translators

## Support

- 📖 [Documentation](https://texteditor-docs.example.com)
- 💬 [Community Discussions](https://github.com/yourusername/TextEditor/discussions)
- 🐛 [Issue Tracker](https://github.com/yourusername/TextEditor/issues)
- 📧 [Contact](mailto:support@texteditor.example.com)

---

**Made with ❤️ by the TextEditor Team**

*Supporting Windows, macOS, and Linux with native performance and user experience.*

*Ian se la come*
*Carlos mama verga*
