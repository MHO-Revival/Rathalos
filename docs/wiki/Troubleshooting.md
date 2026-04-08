# Troubleshooting

This guide covers common issues and their solutions when running the Rathalos server.

## Table of Contents

- [Installation Issues](#installation-issues)
- [Database Problems](#database-problems)
- [Network & Connection](#network--connection)
- [Server Startup](#server-startup)
- [Client Connection](#client-connection)
- [Performance Issues](#performance-issues)
- [Error Messages](#error-messages)

---

## Installation Issues

### .NET SDK Not Found

**Symptoms:**
```
The command could not be loaded, possibly because:
  * You intended to execute a .NET application
  * The SDK 'Microsoft.NET.Sdk' specified could not be found
```

**Solutions:**

1. **Install .NET 10 SDK**:
   - Download from: https://dotnet.microsoft.com/download/dotnet/10.0
   - Verify: `dotnet --version`

2. **Check global.json**:
   ```json
   {
     "sdk": {
       "version": "10.0.100",
       "rollForward": "latestMinor"
     }
   }
   ```

3. **Update PATH environment variable**:
   - Windows: Add `C:\Program Files\dotnet` to PATH
   - Linux/macOS: Add `/usr/local/share/dotnet` to PATH

### NuGet Restore Fails

**Symptoms:**
```
error NU1301: Unable to load the service index for source
```

**Solutions:**

1. **Clear NuGet cache**:
   ```powershell
   dotnet nuget locals all --clear
   ```

2. **Check internet connection** and firewall settings

3. **Use explicit NuGet source**:
   ```powershell
   dotnet restore --source https://api.nuget.org/v3/index.json
   ```

### Build Errors

**Symptoms:**
```
CSxxxx: The type or namespace name 'X' could not be found
```

**Solutions:**

1. **Clean and rebuild**:
   ```powershell
   dotnet clean
   dotnet restore
   dotnet build
   ```

2. **Check project references**:
   - Ensure all projects are in the same solution
   - Verify `<ProjectReference>` paths

3. **Update dependencies**:
   ```powershell
   dotnet list package --outdated
   dotnet restore
   ```

---

## Database Problems

### Cannot Connect to PostgreSQL

**Symptoms:**
```
Npgsql.NpgsqlException: Failed to connect to [::1]:5432
```

**Solutions:**

1. **Verify PostgreSQL is running**:
   ```powershell
   # Windows
   Get-Service postgresql*

   # Linux
   sudo systemctl status postgresql

   # macOS
   brew services list
   ```

2. **Check connection string**:
   ```json
   {
     "ConnectionStrings": {
       "rathalos-world": "Host=localhost;Port=5432;Database=rathalos-world;Username=postgres;Password=YOUR_PASSWORD"
     }
   }
   ```

3. **Test connection manually**:
   ```powershell
   psql -h localhost -U postgres -d rathalos-world
   ```

4. **Allow local connections** in `pg_hba.conf`:
   ```
   # IPv4 local connections:
   host    all             all             127.0.0.1/32            md5
   ```

### Database Does Not Exist

**Symptoms:**
```
Npgsql.PostgresException: 3D000: database "rathalos-world" does not exist
```

**Solutions:**

1. **Create database**:
   ```sql
   CREATE DATABASE "rathalos-world";
   ```

2. **Run migrations**:
   ```powershell
   dotnet ef database update --project Core/Rathalos.Core.Migrations
   ```

### Migration Errors

**Symptoms:**
```
The entity type 'X' requires a primary key to be defined
```

**Solutions:**

1. **Delete and recreate database**:
   ```sql
   DROP DATABASE "rathalos-world";
   CREATE DATABASE "rathalos-world";
   ```
   ```powershell
   dotnet ef database update --project Core/Rathalos.Core.Migrations
   ```

2. **Remove old migrations** (development only):
   ```powershell
   # Delete Migrations folder contents
   dotnet ef migrations add InitialCreate --project Core/Rathalos.Core.Migrations
   dotnet ef database update --project Core/Rathalos.Core.Migrations
   ```

### Connection Pool Exhaustion

**Symptoms:**
```
System.InvalidOperationException: The connection pool has been exhausted
```

**Solutions:**

1. **Increase pool size** in connection string:
   ```json
   "rathalos-world": "Host=localhost;Database=rathalos-world;Username=postgres;Password=pass;MaxPoolSize=100"
   ```

2. **Ensure connections are disposed**:
   ```csharp
   await using var context = new RathalosDbContext();
   // Operations...
   ```

3. **Check for connection leaks** in your code

---

## Network & Connection

### Port Already in Use

**Symptoms:**
```
System.Net.Sockets.SocketException: Only one usage of each socket address is normally permitted
```

**Solutions:**

1. **Find process using port**:
   ```powershell
   # Windows
   netstat -ano | findstr :8142
   taskkill /PID <PID> /F

   # Linux/macOS
   lsof -i :8142
   kill -9 <PID>
   ```

2. **Change server port** in `appsettings.json`:
   ```json
   {
     "Server": {
       "Port": 8143
     }
   }
   ```

### Firewall Blocking Connections

**Symptoms:**
- Server starts but clients cannot connect
- Connection timeout errors

**Solutions:**

1. **Allow port through Windows Firewall**:
   ```powershell
   New-NetFirewallRule -DisplayName "Rathalos Server" -Direction Inbound -LocalPort 8142 -Protocol TCP -Action Allow
   ```

2. **Allow port through Linux firewall**:
   ```bash
   sudo ufw allow 8142/tcp
   sudo ufw reload
   ```

3. **Check antivirus software** - may block server

### Cannot Access from Other Computers

**Symptoms:**
- Server accessible locally but not from network

**Solutions:**

1. **Bind to all interfaces**:
   ```json
   {
     "Server": {
       "AddressIP": "0.0.0.0"
     }
   }
   ```

2. **Configure router port forwarding**:
   - Forward external port 8142 to internal IP:8142

3. **Disable IPv6** if causing issues:
   ```json
   "AddressIP": "0.0.0.0"  // Forces IPv4
   ```

---

## Server Startup

### Server Crashes Immediately

**Symptoms:**
- Server starts and immediately exits
- No error message

**Solutions:**

1. **Check logs** for errors:
   - Look in `logs/` directory
   - Check console output

2. **Run with verbose logging**:
   ```json
   {
     "Logging": {
       "LogLevel": {
         "Default": "Debug"
       }
     }
   }
   ```

3. **Verify all dependencies** are installed

### Configuration File Not Found

**Symptoms:**
```
System.IO.FileNotFoundException: The configuration file 'appsettings.json' was not found
```

**Solutions:**

1. **Ensure file exists** in correct location:
   ```
   GUI/Rathalos.ConsoleUI.World/appsettings.json
   ```

2. **Check file is copied on build**:
   ```xml
   <ItemGroup>
     <Content Include="appsettings.json">
       <CopyToOutputDirectory>Always</CopyToOutputDirectory>
     </Content>
   </ItemGroup>
   ```

### Dependency Injection Errors

**Symptoms:**
```
System.InvalidOperationException: Unable to resolve service for type 'X'
```

**Solutions:**

1. **Register service** in `Program.cs`:
   ```csharp
   builder.Services.AddScoped<ICharacterService, CharacterService>();
   ```

2. **Check service lifetime**:
   - Singleton: Application lifetime
   - Scoped: Per-request
   - Transient: Each use

---

## Client Connection

### Client Cannot Find Server

**Symptoms:**
- Client shows "Server not found"
- Connection timeout

**Solutions:**

1. **Check hosts file** redirection:
   ```
   C:\Windows\System32\drivers\etc\hosts
   ```
   Should contain:
   ```
   127.0.0.1  mho-auth.tencent.com
   127.0.0.1  mho-world.tencent.com
   ```

2. **Flush DNS cache**:
   ```powershell
   ipconfig /flushdns
   ```

3. **Verify server is running**:
   ```powershell
   Test-NetConnection -ComputerName localhost -Port 8142
   ```

### Protocol Version Mismatch

**Symptoms:**
- Client disconnects immediately after connecting
- "Version mismatch" error

**Solutions:**

1. **Match protocol version** in `appsettings.json`:
   ```json
   {
     "Server": {
       "ProtocolVersion": "1.0.3+56e1f37"
     }
   }
   ```

2. **Check client version** matches expected version

### Authentication Failed

**Symptoms:**
- Client shows "Authentication failed"
- Login rejected

**Solutions:**

1. **Verify security key**:
   ```json
   {
     "Server": {
       "SecurityKey": "MhoSrv4EverBest!"
     }
   }
   ```

2. **Check database** for user account

3. **Review authentication logs**

---

## Performance Issues

### High CPU Usage

**Symptoms:**
- Server uses 100% CPU
- Slow response times

**Solutions:**

1. **Enable release mode optimizations**:
   ```powershell
   dotnet run --configuration Release
   ```

2. **Profile the application**:
   ```powershell
   dotnet trace collect --process-id <PID>
   ```

3. **Check for infinite loops** in game logic

4. **Optimize database queries**:
   - Add indexes
   - Use async operations
   - Enable query caching

### Memory Leaks

**Symptoms:**
- Memory usage constantly increasing
- OutOfMemoryException

**Solutions:**

1. **Profile memory**:
   ```powershell
   dotnet-dump collect --process-id <PID>
   ```

2. **Check for undisposed resources**:
   ```csharp
   // Bad
   var context = new DbContext();

   // Good
   await using var context = new DbContext();
   ```

3. **Clear event handlers**:
   ```csharp
   player.OnDisconnect -= HandleDisconnect;
   ```

### Slow Database Operations

**Symptoms:**
- Queries take seconds to execute
- High database CPU

**Solutions:**

1. **Add indexes**:
   ```sql
   CREATE INDEX idx_character_name ON characters(name);
   ```

2. **Enable connection pooling**:
   ```json
   "rathalos-world": "...;Pooling=true;MinPoolSize=5;MaxPoolSize=50"
   ```

3. **Use async operations**:
   ```csharp
   await context.Characters.ToListAsync();
   ```

4. **Optimize queries**:
   - Use `.AsNoTracking()` for read-only
   - Avoid N+1 queries with `.Include()`

---

## Error Messages

### Common Errors

#### Error: "Access to the path is denied"

**Cause**: Insufficient permissions

**Solution**:
- Run as Administrator (Windows)
- Use `sudo` (Linux/macOS)
- Check file permissions

#### Error: "Assembly not found"

**Cause**: Missing or incorrect reference

**Solution**:
```powershell
dotnet restore
dotnet build
```

#### Error: "The SSL connection could not be established"

**Cause**: PostgreSQL SSL configuration

**Solution**:
Add to connection string:
```json
"rathalos-world": "...;SslMode=Disable"
```

#### Error: "Sequence contains no elements"

**Cause**: Empty query result

**Solution**:
Use safe methods:
```csharp
// Bad
var item = items.First();

// Good
var item = items.FirstOrDefault();
if (item != null) { ... }
```

---

## Getting Help

If you're still experiencing issues:

1. **Check the logs**:
   - Look in `logs/` directory
   - Enable debug logging

2. **Search GitHub Issues**:
   - https://github.com/MHO-Revival/Rathalos/issues

3. **Ask on Discord**:
   - https://discord.gg/mho-revival

4. **Create a new issue**:
   - Include error messages
   - Provide steps to reproduce
   - Attach relevant logs

---

## Diagnostic Commands

### System Information

```powershell
# .NET version
dotnet --info

# PostgreSQL version
psql --version

# Server status
Get-Process | Where-Object {$_.Name -like "*Rathalos*"}
```

### Network Diagnostics

```powershell
# Test port
Test-NetConnection -ComputerName localhost -Port 8142

# Show listening ports
netstat -an | findstr :8142
```

### Database Diagnostics

```sql
-- Check connections
SELECT * FROM pg_stat_activity WHERE datname = 'rathalos-world';

-- Check table sizes
SELECT 
    schemaname,
    tablename,
    pg_size_pretty(pg_total_relation_size(schemaname||'.'||tablename)) AS size
FROM pg_tables
WHERE schemaname = 'public'
ORDER BY pg_total_relation_size(schemaname||'.'||tablename) DESC;
```

---

## Next Steps

- [Installation Guide](Installation-Guide)
- [Server Configuration](Server-Configuration)
- [FAQ](FAQ)
