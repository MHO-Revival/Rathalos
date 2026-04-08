# Server Configuration

This guide covers all configuration options available in the Rathalos server.

## Configuration Files

### appsettings.json

The main configuration file located at `GUI\Rathalos.ConsoleUI.World\appsettings.json`:

```json
{
  "ConnectionStrings": {
    "rathalos-world": "Host=localhost;Database=rathalos-world;Username=postgres;Password=your_password"
  },
  "Server": {
    "Port": 8142,
    "AddressIP": "127.0.0.1",
    "ProtocolVersion": "1.0.3+56e1f37",
    "SecurityKey": "MhoSrv4EverBest!",
    "SaveInterval": "01:00:00"
  },
  "Logging": {
    "LogLevel": {
      "Default": "Information",
      "Microsoft": "Warning",
      "System": "Warning"
    }
  }
}
```

## Server Settings

### Network Configuration

#### Port
```json
"Port": 8142
```
- **Description**: TCP port the server listens on
- **Default**: `8142`
- **Range**: `1024-65535`
- **Notes**: Must not conflict with other services

#### Address IP
```json
"AddressIP": "127.0.0.1"
```
- **Description**: IP address to bind to
- **Options**:
  - `127.0.0.1` - Local only
  - `0.0.0.0` - All interfaces
  - Specific IP - Specific network interface
- **Default**: `127.0.0.1`

#### Protocol Version
```json
"ProtocolVersion": "1.0.3+56e1f37"
```
- **Description**: Game protocol version
- **Format**: `major.minor.patch+commit`
- **Default**: `1.0.3+56e1f37`
- **Notes**: Must match client version

### Security Settings

#### Security Key
```json
"SecurityKey": "MhoSrv4EverBest!"
```
- **Description**: Encryption/signature key for packets
- **Recommendations**:
  - Use strong, unique values in production
  - 16 characters
  - Include uppercase, lowercase, numbers, symbols
- **⚠️ Important**: Change this for production deployments

### Performance Settings

#### Save Interval
```json
"SaveInterval": "01:00:00"
```
- **Description**: How often to auto-save player data
- **Format**: `HH:MM:SS` (TimeSpan)
- **Default**: `01:00:00` (1 hour)
- **Recommendations**:
  - Higher frequency = more DB load, less data loss
  - Lower frequency = better performance, more potential data loss

## Database Configuration

### Connection String Format

```
Host={hostname};Port={port};Database={database};Username={username};Password={password};{options}
```

### Connection String Options

| Parameter | Description | Example |
|-----------|-------------|---------|
| `Host` | PostgreSQL server hostname | `localhost`, `192.168.1.100` |
| `Port` | PostgreSQL port | `5432` |
| `Database` | Database name | `rathalos-world` |
| `Username` | Database user | `postgres` |
| `Password` | User password | `SecureP@ssw0rd` |
| `Pooling` | Enable connection pooling | `true` |
| `MinPoolSize` | Minimum pool size | `1` |
| `MaxPoolSize` | Maximum pool size | `100` |
| `Timeout` | Connection timeout (seconds) | `30` |
| `CommandTimeout` | Command timeout (seconds) | `30` |
| `SslMode` | SSL connection mode | `Disable`, `Require`, `Prefer` |

### Example Connection Strings

#### Local Development
```json
"rathalos-world": "Host=localhost;Database=rathalos-world;Username=postgres;Password=dev123"
```

#### Production with Connection Pooling
```json
"rathalos-world": "Host=db.example.com;Port=5432;Database=rathalos-world;Username=rathalos_app;Password=SecureP@ssw0rd;Pooling=true;MinPoolSize=5;MaxPoolSize=50;SslMode=Require"
```

#### Docker Environment
```json
"rathalos-world": "Host=postgres-container;Database=rathalos-world;Username=rathalos;Password=${DB_PASSWORD}"
```

## Logging Configuration

### Log Levels

Configure logging verbosity per namespace:

```json
"Logging": {
  "LogLevel": {
    "Default": "Information",
    "Microsoft": "Warning",
    "Microsoft.EntityFrameworkCore": "Warning",
    "Rathalos.Servers": "Debug",
    "Rathalos.Core.Protocol": "Information",
    "System": "Warning"
  }
}
```

### Log Level Options

| Level | Description | Use Case |
|-------|-------------|----------|
| `Trace` | Most detailed | Debugging complex issues |
| `Debug` | Detailed info | Development |
| `Information` | General info | Production (default) |
| `Warning` | Potential issues | Production |
| `Error` | Errors only | Production (minimal) |
| `Critical` | Critical errors only | Production (minimal) |
| `None` | No logging | Not recommended |

### File Logging (Optional)

Add Serilog for file logging:

```json
"Serilog": {
  "Using": ["Serilog.Sinks.File"],
  "MinimumLevel": "Information",
  "WriteTo": [
    {
      "Name": "File",
      "Args": {
        "path": "logs/rathalos-.log",
        "rollingInterval": "Day",
        "retainedFileCountLimit": 30
      }
    }
  ]
}
```

## Environment-Specific Configuration

### Development (appsettings.Development.json)

```json
{
  "ConnectionStrings": {
    "rathalos-world": "Host=localhost;Database=rathalos-world-dev;Username=postgres;Password=dev123"
  },
  "Logging": {
    "LogLevel": {
      "Default": "Debug",
      "Rathalos.Servers": "Trace"
    }
  },
  "Server": {
    "Port": 8142,
    "AddressIP": "127.0.0.1"
  }
}
```

### Production (appsettings.Production.json)

```json
{
  "ConnectionStrings": {
    "rathalos-world": "Host=prod-db;Database=rathalos-world;Username=${DB_USER};Password=${DB_PASSWORD};SslMode=Require"
  },
  "Logging": {
    "LogLevel": {
      "Default": "Warning",
      "Rathalos.Servers": "Information"
    }
  },
  "Server": {
    "Port": 8142,
    "AddressIP": "0.0.0.0",
    "SecurityKey": "${SECURITY_KEY}"
  }
}
```

## Environment Variables

Use environment variables for sensitive data:

### Windows (PowerShell)
```powershell
$env:DB_PASSWORD="SecurePassword123"
$env:SECURITY_KEY="YourSecurityKey456"
```

### Linux/macOS (Bash)
```bash
export DB_PASSWORD="SecurePassword123"
export SECURITY_KEY="YourSecurityKey456"
```

### Docker
```yaml
environment:
  - DB_PASSWORD=SecurePassword123
  - SECURITY_KEY=YourSecurityKey456
```

## Advanced Configuration

### Custom Configuration Providers

```csharp
builder.Configuration
    .AddJsonFile("appsettings.json", optional: false)
    .AddJsonFile($"appsettings.{env.EnvironmentName}.json", optional: true)
    .AddEnvironmentVariables("RATHALOS_")
    .AddCommandLine(args);
```

### Configuration Validation

```csharp
services.AddOptions<WorldServerConfiguration>()
    .Bind(configuration.GetSection("Server"))
    .ValidateDataAnnotations()
    .ValidateOnStart();
```

## Configuration Best Practices

1. **Never commit secrets** - Use environment variables or secret managers
2. **Use environment-specific configs** - Separate dev/staging/prod
3. **Validate configuration** - Add data annotations and validation
4. **Document custom settings** - Comment non-obvious options
5. **Use strong security keys** - Generate cryptographically secure keys
6. **Enable connection pooling** - For better database performance
7. **Configure appropriate timeouts** - Based on your network/workload
8. **Rotate secrets regularly** - Update passwords and keys periodically

## Configuration Reference

For a complete list of all configuration options, see:
- [WorldServerConfiguration.cs](https://github.com/MHO-Revival/Rathalos/blob/main/Servers/Rathalos.Servers.Game/Core/Configurations/WorldServerConfiguration.cs)

## Next Steps

- [Running the Server](Running-the-Server)
- [Security Best Practices](Security-Best-Practices)
- [Performance Tuning](Performance-Tuning)

## Troubleshooting

### Configuration Not Loading

Check the environment:
```powershell
dotnet run --environment Production
```

### Invalid Configuration Values

Enable validation:
```json
"Logging": {
  "LogLevel": {
    "Microsoft.Hosting.Lifetime": "Information"
  }
}
```

## Additional Resources

- [ASP.NET Core Configuration](https://docs.microsoft.com/en-us/aspnet/core/fundamentals/configuration/)
- [PostgreSQL Connection Strings](https://www.npgsql.org/doc/connection-string-parameters.html)
