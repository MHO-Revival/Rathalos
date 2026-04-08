# Rathalos - Monster Hunter Online Server Emulator

[![.NET 10](https://img.shields.io/badge/.NET-10-blue.svg)](https://dotnet.microsoft.com/)
[![C# 14.0](https://img.shields.io/badge/C%23-14.0-brightgreen.svg)](https://docs.microsoft.com/en-us/dotnet/csharp/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![GitHub release](https://img.shields.io/github/release/MHO-Revival/Rathalos.svg)](https://github.com/MHO-Revival/Rathalos/releases)

> **Rathalos** is a high-performance server emulator for Monster Hunter Online, designed to revive and preserve the MHO experience for the community.

---

## 🚀 Features

- **Protocol Implementation** - Csproto (game protocol) and Tqqapi (authentication protocol) support
- **TLV-Based Communication** - Efficient binary serialization for network messages
- **Database Management** - PostgreSQL-backed persistence with EF Core migrations
- **Implemented Game Systems**:
  - **Authentication** - QQ-style authentication with encryption
  - **Character Management** - Create, delete, select, and list characters
  - **Network** - Multi-network IP routing, version checking, server lines/channels
  - **Database Records** - Extensive data structures for pets, monsters, items, NPCs, shops
- **Infrastructure**:
  - Automatic database migration on server startup
  - Docker-based PostgreSQL deployment
  - .NET Aspire orchestration for distributed services
  - Comprehensive packet handler system
- **Tools Suite** - Interactive CLI for code generation, IFS tools, and server management
- **Modern Architecture** - Built on .NET 10 with async/await patterns

**Note**: This is an **active development** server emulator. Many game systems are data-ready but not yet fully implemented. Current functionality includes authentication, character management, and server connectivity.

---

## 📁 Project Structure

```
Rathalos/
├── Core/
│   ├── Rathalos.Core.Protocol     # Protocol messages (Csproto, Tqqapi, TLV)
│   ├── Rathalos.Core.ORM          # Entity Framework Core models
│   ├── Rathalos.Core.Migrations   # Database migrations
│   └── Rathalos.Core.Utils        # Shared utilities and helpers
├── Servers/
│   ├── Rathalos.Servers.World     # World server (main game server)
│   └── Rathalos.Servers.Base      # Base server infrastructure
├── Tools/
│   └── Rathalos.CLI               # Command-line interface tool
└── GUI/
    ├── Rathalos.ConsoleUI.World   # Console UI for World server
    └── Rathalos.Distributed       # Distributed management UI
```

---

## 🔧 Prerequisites

- [.NET 10 SDK](https://dotnet.microsoft.com/download/dotnet/10.0)
- [Docker Desktop](https://www.docker.com/products/docker-desktop/) (includes PostgreSQL container)
- [Visual Studio 2026](https://visualstudio.microsoft.com/) or [VS Code](https://code.visualstudio.com/) (optional)

---

## ⚡ Quick Start

### 1. Clone the Repository

```powershell
git clone https://github.com/MHO-Revival/Rathalos.git
cd Rathalos
```

### 2. Start Docker Desktop

Ensure Docker Desktop is running on your system.

### 3. Run Initial Setup

Run the Distributed project **once** to set up Docker containers and database:

```powershell
dotnet run --project GUI/Rathalos.Distributed
```

This will:
- Start PostgreSQL container in Docker
- Create and configure the database
- Apply all migrations automatically
- Set up initial data

### 4. Run the World Server

After the initial setup, start the World Server using Console UI:

```powershell
dotnet run --project GUI/Rathalos.ConsoleUI.World
```

The server is now ready to accept connections!

---

## 📖 Documentation

Comprehensive documentation is available in the [**GitHub Wiki**](https://github.com/MHO-Revival/Rathalos/wiki):

- [Installation Guide](https://github.com/MHO-Revival/Rathalos/wiki/Installation-Guide)
- [Server Configuration](https://github.com/MHO-Revival/Rathalos/wiki/Server-Configuration)
- [Protocol Documentation](https://github.com/MHO-Revival/Rathalos/wiki/Protocol-Documentation)
- [Tools Documentation](https://github.com/MHO-Revival/Rathalos/wiki/Tools-Documentation)
- [Development Guide](https://github.com/MHO-Revival/Rathalos/wiki/Development-Guide)
- [Troubleshooting](https://github.com/MHO-Revival/Rathalos/wiki/Troubleshooting)

---

## 🛠️ Tools

### Rathalos CLI

The Rathalos CLI provides utilities for:

- **XML Code Generator** - Generate protocol classes from XML definitions
- **IFS Tools** - Extract and manage game files
- **MHO Launcher** - Launch client with custom configurations
- **Hosts File Editor** - Modify hosts for server redirection

```powershell
dotnet run --project Tools/Rathalos.CLI
```

### Rathalos Distributed

The Distributed UI provides:

- **Docker Container Management** - Automatic setup of PostgreSQL
- **Database Initialization** - Creates and migrates database automatically
- **Server Monitoring** - Monitor running servers
- **Configuration Management** - Manage server settings

**Note**: Run Distributed **once** before first use to set up the environment.

---

## 🏗️ Architecture

### Core Components

- **Protocol Layer** (`Rathalos.Core.Protocol`)
  - Csproto message definitions
  - Tqqapi authentication protocol
  - TLV (Type-Length-Value) structures
  - Data readers/writers

- **ORM Layer** (`Rathalos.Core.ORM`)
  - Entity models for characters, items, monsters, pets
  - Database context and repositories
  - Query optimizations

- **Server Layer** (`Rathalos.Servers.World`)
  - Network communication (TCP/IP)
  - Packet handlers for game and Tqqapi
  - Game logic and state management
  - Service layer (Character, Experience, Database services)

---

## 🤝 Contributing

We welcome contributions! Please read our [Development Guide](https://github.com/MHO-Revival/Rathalos/wiki/Development-Guide) before submitting pull requests.

### Coding Standards

- Follow the project's [Copilot Instructions](.github/copilot-instructions.md)
- Use `ReadTlvObject`/`WriteTlvObject` for nested TLV structures
- Write unit tests for new features
- Document public APIs with XML comments

---

## 📝 Configuration

### Server Configuration

Key configuration options in `appsettings.json`:

```json
{
  "Server": {
    "Port": 8142,
    "AddressIP": "127.0.0.1",
    "ProtocolVersion": "1.0.3+56e1f37",
    "SecurityKey": "MhoSrv4EverBest!",
    "SaveInterval": "01:00:00"
  }
}
```

**Note**: Database connection string is automatically configured by the Distributed setup. Manual configuration is only needed for advanced scenarios.

See [Server Configuration Wiki](https://github.com/MHO-Revival/Rathalos/wiki/Server-Configuration) for all options.

---

## 🧪 Testing

```powershell
# Run all tests
dotnet test

# Run specific test project
dotnet test Tests/Rathalos.Tests.Protocol
```

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Credits

- **MHO Revival Team** - Server emulation and protocol research
- **Monster Hunter Online Community** - Support and informations
- **[sebastian-heinz](https://github.com/sebastian-heinz)** - [Arrowgene.MonsterHunterOnline](https://github.com/sebastian-heinz/Arrowgene.MonsterHunterOnline) - Original MHO launcher DLL implementation (modified and adapted for this project)

---

## 📞 Contact & Support

- **Discord (Rathalos)**: [Join our server](https://discord.gg/mho-revival)
- **Discord (MHO RE & Dev)**: [Active reverse engineering community](https://discord.gg/3jMpmJN6ej)
- **GitHub Issues**: [Report bugs](https://github.com/MHO-Revival/Rathalos/issues)
- **GitHub Discussions**: [Ask questions](https://github.com/MHO-Revival/Rathalos/discussions)

---

## ⚠️ Disclaimer

This project is for educational and preservation purposes only. Monster Hunter Online and all related trademarks are property of **Capcom Co., Ltd.** and **Tencent Games**. This project is not affiliated with or endorsed by Capcom or Tencent.

---

**Made with ❤️ by the MHO Revival Community**