# Tools Documentation

The Rathalos CLI provides a comprehensive suite of tools for server management, file manipulation, and client configuration through an **interactive menu-driven interface**.

## Rathalos CLI

### Installation

The CLI is included in the main Rathalos project:

```powershell
# Run directly
dotnet run --project Tools/Rathalos.CLI

# Or publish to executable
dotnet publish Tools/Rathalos.CLI --configuration Release --output ./tools
./tools/Rathalos.CLI.exe
```

### Navigation

The CLI uses an **interactive menu system** with **arrow key navigation**:

- **↑/↓ Arrow Keys** - Navigate between menu options
- **Page Up/Page Down** - Quick scroll through long menus
- **Home/End** - Jump to first/last option
- **Enter** - Select the highlighted option
- **Escape** - Return to previous menu or exit

### Main Menu

When you launch the CLI, you'll see an interactive menu:

```
=== Rathalos CLI Menu ===
Use ↑↓ arrows to navigate, Enter to select, Esc to go back

> 🔧 XML Code Generator (T4 Templates)
  📁 IFS Archive Tools
  🚀 MHO Client Launcher
  ⚙️  Configure Hosts File
  🔙 Exit
```

**Note**: Icons (🔧📁🚀) may display as text `[TOOL][DIR][LAUNCH]` depending on your console's emoji support.

---

## 🔧 XML Code Generator

### Purpose

Generates C# protocol classes from XML metalib definitions using T4 templates:
- Adding new protocol messages
- Updating existing message definitions
- Converting XML schemas to strongly-typed C# code

### Interactive Menu

When selected, you'll see a sub-menu:

```
=== XML Code Generator ===

> 📂 Generate from XML File
  📋 View Sample XML Format
  🔙 Return to Main Menu
```

### Usage Flow

1. **Select "Generate from XML File"** using arrow keys and Enter
2. **Enter XML file path** when prompted
3. The tool validates the XML structure
4. **Enter target namespace** (e.g., `Messages`)
   - Full namespace becomes: `Rathalos.Core.Protocol.Messages.{MetalibName}`
5. **Enter output directory** 
   - A subfolder with the metalib name will be created automatically
6. Code is generated with progress feedback:
   ```
   🔍 Validating XML file...
   ✅ XML validation successful!
   📖 Parsing XML file...
   ✅ Parsed metalib 'CustomMessages' version 1.0
   🔄 Converting to code model...
   ✅ Code model created:
      - Constants: 5
      - Enums: 12
      - Interfaces: 3
      - Classes: 45
   🔧 Generating code files...
   💾 Saving generated files...
   🎉 Code generation completed!
   ```

### XML Format Example

```xml
<?xml version="1.0" encoding="utf-8"?>
<metalib name="CustomMessages" version="1.0">
  <struct name="CSCreateRoleReq" id="0x1001">
    <entry name="Name" type="string" />
    <entry name="Gender" type="byte" />
    <entry name="FaceId" type="uint32" />
  </struct>
</metalib>
```

### Generated Output Structure

```
OutputDirectory/
└── CustomMessages/
    ├── Classes/
    │   ├── CSCreateRoleReq.cs
    │   └── ...
    └── Enums/
        ├── Gender.cs
        └── ...
```

---

## 📁 IFS Archive Tools

### Purpose

IFS (Internal File System) tools for extracting and managing game archive files:
- Extract game assets from .ifs archives
- View archive contents
- Create new IFS archives from directories
- Batch processing of multiple archives

### Interactive Menu

```
=== IFS Archive Tools ===

> 📁 Extract IFS Archive(s)
  📦 Create IFS Archive
  🔍 View Archive Contents
  🔙 Return to Main Menu
```

### Extract Archive

1. **Select "Extract IFS Archive(s)"**
2. **Enter path** - Can be:
   - Single `.ifs` file path
   - Directory containing multiple `.ifs` files (searches recursively)
3. **Enter output folder** where extracted files will be saved
4. Extraction process shows progress:
   ```
   🔍 Found 3 IFS archive(s).

   📂 Processing: data1.ifs
   ✅ Extracted 1,234 files

   📂 Processing: data2.ifs
   ✅ Extracted 567 files

   🎉 Extraction completed!
   ```

### Create Archive

1. **Select "Create IFS Archive"**
2. **Enter source directory** containing files to pack
3. **Enter output .ifs file path**
4. Files are compressed and packed with progress feedback

### View Contents

1. **Select "View Archive Contents"**
2. **Enter .ifs file path**
3. Lists all files in the archive:
   ```
   📋 Contents of data.ifs:

   monsters/rathalos.model
   monsters/rathalos.texture
   monsters/lagiacrus.model
   ui/icons/item_001.png
   ui/icons/item_002.png
   ...

   Total: 1,234 files
   ```

### Supported Features

- **Batch extraction** - Process entire directories of .ifs files
- **Progress tracking** - Real-time extraction progress
- **Error handling** - Continues processing on errors
- **Recursive scanning** - Finds .ifs files in subdirectories

---

## 🚀 MHO Client Launcher

### Purpose

Launch the Monster Hunter Online client with advanced features:
- **DLL injection** for custom modifications
- **Process suspension** for safe memory manipulation
- **Administrator privilege handling**
- **Shared memory communication** with TenProxy

### Interactive Menu

```
=== MHO Client Launcher ===

> 🚀 Launch with DLL Injection
  📋 View Usage Instructions
  🔙 Return to Main Menu
```

### Administrator Requirements

The launcher checks for administrator privileges on startup:

```
✅ Running as Administrator
```

Or if not running as admin:
```
💡 WARNING: Not running as Administrator!
   DLL injection requires Administrator privileges.
   Consider restarting the CLI as Administrator.
```

### Launch with DLL Injection

1. **Select "Launch with DLL Injection"**
2. **Enter client executable path** (e.g., `C:\Games\MHO\mhol.exe`)
3. **Enter working directory** (usually the game's install folder)
4. **Enter command line arguments** (optional, press Enter to skip)
5. **Enter DLL path** - Defaults to `mhoclient_dll.dll` in current directory
6. Launch process:
   ```
   🔄 Creating suspended process...
   ✅ Process created (PID: 12345)

   💉 Injecting DLL...
   ✅ DLL injected successfully

   🔄 Resuming process...
   ✅ Client launched successfully!

   📊 Process Information:
      PID: 12345
      Handle: 0x000001A4
      Main Thread ID: 5678
   ```

### Configuration Options

When prompted, you can specify:

- **Executable Path**: Full path to the MHO client executable
- **Working Directory**: Game installation folder (contains game data)
- **Command Arguments**: Additional startup parameters (optional)
- **DLL Path**: Path to custom DLL for injection

### Default DLL Path

The tool looks for DLL in this order:
1. Path you specify when prompted
2. `mhoclient_dll.dll` in current directory
3. `bin\mhoclient_dll.dll` relative to CLI location

### Features

- **Suspended process creation** - Client starts paused for safe DLL injection
- **Memory injection** - Safely injects DLL into process memory space
- **Error handling** - Detailed error messages for troubleshooting
- **Process monitoring** - Displays process information after launch

---

## ⚙️ Configure Hosts File

### Purpose

Automatically configure the Windows hosts file to redirect MHO server traffic:
- Redirect authentication servers to localhost
- Redirect game servers to localhost
- Safe editing with administrator privilege checks
- View current configuration status

### Required Hosts Entries

The tool manages these redirects:
```
127.0.0.1  tqos.gamesafe.qq.com
127.0.0.1  down.qq.com
127.0.0.1  stat.iips.qq.com
127.0.0.1  ied-tqos.qq.com
127.0.0.1  apps.game.qq.com
```

### Interactive Menu

```
=== Hosts File Configuration ===

> 📊 View Hosts Status
  ➕ Add Required Entries
  ➖ Remove MHO Entries
  🔙 Return to Main Menu
```

### Administrator Requirements

**This feature REQUIRES Administrator privileges!**

If not running as admin:
```
❌ This operation requires Administrator privileges!
   Please restart the CLI as Administrator.
```

If running as admin:
```
✅ Running as Administrator
```

### View Hosts Status

Shows the current state of all required entries:

```
📊 Hosts File Status
═══════════════════════════════════════

Host Entry                    Status
─────────────────────────────────────
tqos.gamesafe.qq.com         ✅ Configured
down.qq.com                   ✅ Configured
stat.iips.qq.com             ❌ Not configured
ied-tqos.qq.com              ✅ Configured
apps.game.qq.com             ❌ Not configured

Summary: 3 of 5 entries configured
```

### Add Required Entries

1. **Select "Add Required Entries"**
2. Tool checks existing entries
3. Only missing entries are added
4. Confirmation:
   ```
   ➕ Adding Required Hosts Entries

   ✅ Added: stat.iips.qq.com → 127.0.0.1
   ✅ Added: apps.game.qq.com → 127.0.0.1
   ℹ️  Skipped: tqos.gamesafe.qq.com (already configured)

   🎉 Hosts file updated successfully!
   ```

### Remove MHO Entries

1. **Select "Remove MHO Entries"**
2. Removes all MHO-related redirects
3. Confirmation:
   ```
   ➖ Removing MHO Hosts Entries

   ✅ Removed: tqos.gamesafe.qq.com
   ✅ Removed: down.qq.com
   ✅ Removed: stat.iips.qq.com

   🎉 Hosts file cleaned successfully!
   ```

### Safety Features

- **Backup creation** - Automatic backup before modifications
- **Administrator check** - Prevents running without proper privileges
- **Validation** - Verifies entries before adding
- **Duplicate prevention** - Won't add entries that already exist
- **Error handling** - Clear error messages if modifications fail

### Hosts File Location

Windows: `C:\Windows\System32\drivers\etc\hosts`

---

## 💡 Tips and Best Practices

### Navigation Shortcuts

- **Arrow Keys**: Primary navigation method
- **Page Up/Down**: Quickly scroll through long option lists
- **Home**: Jump to first menu item
- **End**: Jump to last menu item
- **Enter**: Confirm selection
- **Escape**: Go back or exit

### Console Display

The CLI automatically detects your console's emoji support:

- **Emoji-capable consoles** (Windows Terminal, VS Code terminal):
  ```
  🔧 XML Code Generator
  📁 IFS Archive Tools
  ```

- **Legacy consoles** (CMD, PowerShell ISE):
  ```
  [TOOL] XML Code Generator
  [DIR] IFS Archive Tools
  ```

### Running as Administrator

For full functionality (DLL injection, hosts file editing):

**Windows PowerShell:**
```powershell
Start-Process powershell -Verb runAs -ArgumentList "dotnet run --project Tools/Rathalos.CLI"
```

**Command Prompt:**
```batch
runas /user:Administrator "dotnet run --project Tools/Rathalos.CLI"
```

**Or** right-click the published .exe and select "Run as Administrator"

### Batch Operations

For automating repetitive tasks, use PowerShell scripting:

**Example - Extract Multiple Archives:**
```powershell
# Set paths
$ifsPath = "C:\MHO\Archives"
$outputPath = "C:\MHO\Extracted"

# The CLI will process all .ifs files in the directory
# Just enter the paths when prompted after selecting the extract option
```

---

## 🗄️ Database Management

**Note**: With the Distributed setup, database management is **automatic**. These commands are for advanced users only.

### Migrations (Advanced)

The Distributed project handles migrations automatically, but manual commands are available:

#### Create Migration
```powershell
dotnet ef migrations add MigrationName --project Core/Rathalos.Core.Migrations
```

#### Apply Migrations
```powershell
dotnet ef database update --project Core/Rathalos.Core.Migrations
```

#### Rollback Migration
```powershell
dotnet ef database update PreviousMigrationName --project Core/Rathalos.Core.Migrations
```

### Database Backup (Docker)

To backup the PostgreSQL database running in Docker:

```powershell
# Backup
docker exec rathalos-postgres pg_dump -U postgres rathalos-world > backup.sql

# Restore
docker exec -i rathalos-postgres psql -U postgres rathalos-world < backup.sql
```

---

## ❓ Troubleshooting

### CLI Won't Launch

**Issue**: `The application to execute does not exist`

**Solution**:
```powershell
dotnet restore Tools/Rathalos.CLI
dotnet build Tools/Rathalos.CLI
dotnet run --project Tools/Rathalos.CLI
```

### Menu Navigation Not Working

**Issue**: Arrow keys print characters instead of navigating

**Solution**:
- Don't run in PowerShell ISE (not supported)
- Use Windows Terminal, PowerShell 7+, or CMD
- VS Code integrated terminal works well

### DLL Injection Fails

**Issue**: "Access Denied" or injection errors

**Solution**:
- Ensure running as Administrator
- Check DLL path is correct
- Verify DLL is compiled for correct architecture (x86/x64)
- Check antivirus isn't blocking injection

### Hosts File Changes Don't Work

**Issue**: Can't modify hosts file

**Solution**:
- **Must run as Administrator**
- Check antivirus isn't protecting the hosts file
- Verify hosts file exists: `C:\Windows\System32\drivers\etc\hosts`
- Try manually editing to verify file isn't corrupted

### IFS Extraction Errors

**Issue**: Archive extraction fails or produces corrupted files

**Solution**:
- Verify .ifs file isn't corrupted (re-download if needed)
- Check available disk space
- Ensure output directory is writable
- Try extracting to a different location

### Emoji/Icons Not Displaying

**Issue**: Icons show as `[TOOL]` `[DIR]` instead of 🔧 📁

**Solution**:
This is normal for older consoles. For better display:
- Use Windows Terminal (recommended)
- Use Visual Studio Code integrated terminal
- Update to PowerShell 7+

### Process Already Running

**Issue**: "Client already running" when launching

**Solution**:
```powershell
# Kill existing MHO processes
Get-Process | Where-Object {$_.Name -like "*mho*"} | Stop-Process -Force
```

---

## 📚 Feature Reference

### Quick Command Summary

Since the CLI is menu-driven, here's what each tool does:

| Tool | Purpose | Requires Admin |
|------|---------|----------------|
| **XML Code Generator** | Convert XML metalib to C# code | ❌ No |
| **IFS Archive Tools** | Extract/create game archives | ❌ No |
| **MHO Client Launcher** | Launch client with DLL injection | ✅ Yes |
| **Configure Hosts File** | Redirect MHO servers | ✅ Yes |

### Keyboard Shortcuts

| Key | Action |
|-----|--------|
| `↑` / `↓` | Navigate menu options |
| `Page Up` / `Page Down` | Quick scroll |
| `Home` / `End` | Jump to first/last |
| `Enter` | Select option |
| `Escape` | Go back / Exit |

### Common Workflows

#### First-Time Setup
```
1. Launch CLI as Administrator
2. Select "Configure Hosts File"
3. Select "Add Required Entries"
4. Return to main menu
5. Ready to launch client!
```

#### Extract Game Files
```
1. Launch CLI (no admin needed)
2. Select "IFS Archive Tools"
3. Select "Extract IFS Archive(s)"
4. Enter path to .ifs file(s)
5. Enter output directory
6. Wait for extraction
```

#### Generate Protocol Code
```
1. Launch CLI (no admin needed)
2. Select "XML Code Generator"
3. Select "Generate from XML File"
4. Enter XML file path
5. Enter namespace and output directory
6. Review generated code
```

#### Launch Client
```
1. Launch CLI as Administrator
2. Select "MHO Client Launcher"
3. Select "Launch with DLL Injection"
4. Enter client path and DLL path
5. Client launches with modifications
```

---

## Next Steps

- [Development Guide](Development-Guide)
- [Contributing](Contributing)
- [API Reference](API-Reference)
