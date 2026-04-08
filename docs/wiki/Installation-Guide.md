# Installation Guide

This guide will walk you through installing and configuring the Rathalos server emulator.

## Prerequisites

Before you begin, ensure you have the following installed:

### Required Software

1. **.NET 10 SDK**
   - Download from: https://dotnet.microsoft.com/download/dotnet/10.0
   - Verify installation: `dotnet --version`

2. **Docker Desktop**
   - Download from: https://www.docker.com/products/docker-desktop/
   - Includes PostgreSQL container (no manual PostgreSQL installation needed)
   - Verify installation: `docker --version`

3. **Git** (for cloning the repository)
   - Download from: https://git-scm.com/downloads

### Optional but Recommended

- **Visual Studio 2026** or **VS Code** for development
- **Docker Desktop Dashboard** for container management (included with Docker Desktop)
- **Postman** or similar tool for API testing

## Installation Steps

### 1. Clone the Repository

```powershell
# Clone the repository
git clone https://github.com/MHO-Revival/Rathalos.git

# Navigate to the project directory
cd Rathalos
```

### 2. Start Docker Desktop

Ensure Docker Desktop is running on your system. You should see the Docker icon in your system tray.

### 3. Run Initial Setup with Distributed

Run the **Rathalos.Distributed** project to start the required infrastructure:

```powershell
dotnet run --project GUI/Rathalos.Distributed
```

This will automatically:
- ✅ Start PostgreSQL container in Docker
- ✅ Start pgAdmin container (accessible at http://localhost:8080)
- ✅ Create persistent data volume for the database
- ✅ Start the World server with database connection

The Distributed project uses **.NET Aspire** for orchestration and will show a dashboard with the status of all services.

**Important**: Keep this terminal window open - it manages all the containers. Press `Ctrl+C` to stop all services.

### 4. Build the Solution (Optional)

If you want to verify everything builds correctly:

```powershell
# Restore NuGet packages
dotnet restore

# Build in Release configuration
dotnet build --configuration Release
```

### 5. Run the World Server

After the initial setup, start the World Server using Console UI:

```powershell
dotnet run --project GUI/Rathalos.ConsoleUI.World
```

**Alternative**: Direct server launch (without Console UI):

```powershell
dotnet run --project Servers/Rathalos.Servers.Game
```

### 6. Verify Installation

Once the World Server starts, you should see:

```
[INFO] Starting Rathalos World Server...
[INFO] Connecting to database...
[INFO] Database connection established
[INFO] Server listening on 127.0.0.1:8142
[INFO] Protocol version: 1.0.3+56e1f37
[INFO] Server ready to accept connections
```

The server is now running and ready to accept client connections!

### 7. Stopping the Server

To stop the server:
- Press `Ctrl+C` in the console window
- Or close the console window

To stop the Docker containers:
```powershell
# View running containers
docker ps

# Stop PostgreSQL container
docker stop rathalos-postgres

# Or stop all containers
docker stop $(docker ps -q)
```

## Docker Management

### Viewing Containers

Check Docker containers status:

```powershell
# List running containers
docker ps

# List all containers (including stopped)
docker ps -a

# View container logs
docker logs rathalos-postgres
```

### Managing Database Container

```powershell
# Start container
docker start rathalos-postgres

# Stop container
docker stop rathalos-postgres

# Restart container
docker restart rathalos-postgres

# Remove container (⚠️ deletes data!)
docker rm -f rathalos-postgres
```

### Accessing Database

Connect to PostgreSQL running in Docker:

```powershell
# Using docker exec
docker exec -it rathalos-postgres psql -U postgres -d rathalos-world

# Or use connection string from any PostgreSQL client
Host=localhost;Port=5432;Database=rathalos-world;Username=postgres;Password=<configured_password>
```

## Network Configuration

### Firewall Rules

Allow incoming connections on the server port:

#### Windows Firewall

```powershell
New-NetFirewallRule `
  -DisplayName "Rathalos Server" `
  -Direction Inbound `
  -LocalPort 8142 `
  -Protocol TCP `
  -Action Allow
```

#### Linux (UFW)

```bash
sudo ufw allow 8142/tcp
sudo ufw reload
```

### Port Forwarding (for remote access)

If hosting publicly, forward port `8142` in your router settings to your server's local IP.

## Directory Structure

After installation, your directory should look like this:

```
Rathalos/
├── Core/
│   ├── Rathalos.Core.Protocol/
│   ├── Rathalos.Core.ORM/
│   ├── Rathalos.Core.Migrations/
│   └── Rathalos.Core.Utils/
├── Servers/
│   └── Rathalos.Servers.Game/
├── Tools/
│   └── Rathalos.CLI/
├── GUI/
│   ├── Rathalos.ConsoleUI.World/
│   │   ├── appsettings.json  ← Your configuration
│   │   └── ...
│   └── Rathalos.Distributed/
└── publish/ (if you published)
```

## Troubleshooting

### Docker Not Running

**Error**: `Cannot connect to the Docker daemon`

**Solution**:
1. Start Docker Desktop from the Start menu
2. Wait for Docker to fully start (whale icon in system tray)
3. Verify: `docker ps`

### Docker Container Already Exists

**Error**: `Container name 'rathalos-postgres' already in use`

**Solution**:
```powershell
# Option 1: Use existing container
docker start rathalos-postgres

# Option 2: Remove and recreate
docker rm -f rathalos-postgres
dotnet run --project GUI/Rathalos.Distributed
```

### Database Connection Errors

**Error**: `Failed to connect to database`

**Solution**:
1. Verify Docker container is running: `docker ps`
2. Check container logs: `docker logs rathalos-postgres`
3. Restart container: `docker restart rathalos-postgres`
4. If all else fails, re-run Distributed setup

### Port Already in Use (8142)

**Error**: `Address already in use: 8142`

**Solution**:
1. Find the process using the port:
   ```powershell
   Get-NetTCPConnection -LocalPort 8142
   ```
2. Stop the process:
   ```powershell
   Stop-Process -Id <ProcessID>
   ```
3. Or change the port in `appsettings.json`

### Port Already in Use (5432 - PostgreSQL)

**Error**: Docker can't start PostgreSQL on port 5432

**Solution**:
1. Stop any local PostgreSQL service:
   ```powershell
   Stop-Service postgresql*
   ```
2. Or configure Docker container to use a different port

### Distributed Setup Fails

**Error**: Setup doesn't complete successfully

**Solution**:
1. Ensure Docker Desktop is running
2. Check Docker has sufficient resources (Settings → Resources)
3. View detailed logs in the console
4. Clean up and retry:
   ```powershell
   docker rm -f rathalos-postgres
   docker volume prune
   dotnet run --project GUI/Rathalos.Distributed
   ```

### .NET SDK Not Found

**Error**: `The SDK 'Microsoft.NET.Sdk' specified could not be found`

**Solution**:
- Download and install .NET 10 SDK from https://dotnet.microsoft.com/
- Restart your terminal after installation
- Verify: `dotnet --version` should show 10.x.x

### Manual Database Setup (Advanced)

If you prefer not to use Docker and want to manually set up PostgreSQL:

1. Install PostgreSQL 13+ locally
2. Create database: `CREATE DATABASE "rathalos-world";`
3. Update connection string in `appsettings.json`
4. Run migrations manually:
   ```powershell
   dotnet tool install --global dotnet-ef
   dotnet ef database update --project Core/Rathalos.Core.Migrations
   ```

**Note**: The Distributed project is designed for Docker. Manual setup requires additional configuration.

## Quick Setup Checklist

Use this checklist to ensure you've completed all steps:

- [ ] ✅ .NET 10 SDK installed and verified
- [ ] ✅ Docker Desktop installed and running
- [ ] ✅ Repository cloned from GitHub
- [ ] ✅ Ran `Rathalos.Distributed` once for initial setup
- [ ] ✅ Docker container `rathalos-postgres` is running
- [ ] ✅ Started `Rathalos.ConsoleUI.World` successfully
- [ ] ✅ Server shows "ready to accept connections"
- [ ] ✅ Firewall configured (if needed)

## Next Steps

- [Server Configuration](Server-Configuration) - Configure advanced options
- [Running the Server](Running-the-Server) - Day-to-day operations
- [Client Setup](Client-Configuration) - Connect your MHO client
- [Tools Documentation](Tools-Documentation) - Use CLI tools

## Additional Help

- [Troubleshooting Guide](Troubleshooting) - Detailed troubleshooting
- [GitHub Issues](https://github.com/MHO-Revival/Rathalos/issues) - Report bugs
- [Discord Community](https://discord.gg/mho-revival) - Get help from the community
