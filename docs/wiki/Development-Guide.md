# Development Guide

Welcome to the Rathalos development guide! This document will help you set up your development environment and understand the codebase.

## Table of Contents

- [Development Environment Setup](#development-environment-setup)
- [Project Structure](#project-structure)
- [Coding Standards](#coding-standards)
- [Development Workflow](#development-workflow)
- [Testing](#testing)
- [Debugging](#debugging)

---

## Development Environment Setup

### Required Software

1. **.NET 10 SDK**
   - Download: https://dotnet.microsoft.com/download/dotnet/10.0

2. **IDE (Choose one)**
   - **Visual Studio 2026** (Recommended for Windows)
     - Download: https://visualstudio.microsoft.com/
     - Workloads: ".NET desktop development", "ASP.NET and web development"
   - **Visual Studio Code**
     - Download: https://code.visualstudio.com/
     - Extensions: C# Dev Kit, .NET Extension Pack

3. **PostgreSQL 13+**
   - Download: https://www.postgresql.org/download/
   - GUI: pgAdmin 4 (included with PostgreSQL)

4. **Git**
   - Download: https://git-scm.com/downloads

### Optional Tools

- **GitHub Desktop** - Git GUI client
- **Postman** - API testing
- **Docker Desktop** - Container development
- **dotMemory** - Memory profiling
- **dotTrace** - Performance profiling

### Clone Repository

```powershell
git clone https://github.com/MHO-Revival/Rathalos.git
cd Rathalos
```

### Initial Setup

```powershell
# Restore NuGet packages
dotnet restore

# Build solution
dotnet build

# Setup database
dotnet ef database update --project Core/Rathalos.Core.Migrations

# Run tests
dotnet test
```

---

## Project Structure

```
Rathalos/
├── .github/
│   ├── workflows/           # CI/CD pipelines
│   └── copilot-instructions.md  # Coding guidelines
│
├── Core/
│   ├── Rathalos.Core.Protocol/
│   │   ├── Messages/
│   │   │   ├── Csproto/     # Game protocol messages
│   │   │   ├── Tqqapi/      # Auth protocol messages
│   │   │   └── Custom/      # Custom TLV structures
│   │   ├── Data/            # Game data (monsters, items, etc.)
│   │   └── Tools/           # Protocol utilities
│   │
│   ├── Rathalos.Core.ORM/
│   │   ├── Entities/        # Database entities
│   │   ├── Context/         # DbContext
│   │   └── Repositories/    # Data access layer
│   │
│   ├── Rathalos.Core.Migrations/
│   │   └── Migrations/      # EF Core migrations
│   │
│   └── Rathalos.Core.Utils/
│       ├── IO/              # Binary I/O utilities
│       └── Extensions/      # C# extensions
│
├── Servers/
│   ├── Rathalos.Servers.Base/
│   │   ├── Network/         # Base networking
│   │   └── Infrastructure/  # Shared server code
│   │
│   └── Rathalos.Servers.Game/ (World Server)
│       ├── Core/
│       │   ├── Network/     # World server networking
│       │   ├── Game/        # Game logic
│       │   │   ├── Actors/  # Character, Pet, Monster
│       │   │   ├── Attributes/
│       │   │   ├── Storages/
│       │   │   └── World/   # Maps and zones
│       │   └── Databases/   # Database records
│       │
│       ├── Handlers/
│       │   ├── Game/        # Game packet handlers
│       │   └── Tqqapi/      # Auth packet handlers
│       │
│       └── Services/        # Business logic services
│
├── Tools/
│   └── Rathalos.CLI/        # Command-line tools
│       ├── Menu/            # CLI menu system
│       └── Options/         # Tool implementations
│
├── GUI/
│   ├── Rathalos.ConsoleUI.World/  # Console UI
│   └── Rathalos.Distributed/      # Distributed UI
│
└── docs/
    └── wiki/                # Documentation
```

---

## Coding Standards

### Follow Copilot Instructions

Always follow the guidelines in `.github/copilot-instructions.md`:

> **For TLV nested sub-structures**, use the existing `ReadTlvObject`/`WriteTlvObject` helpers. Do not create separate `ReadTlvInlineObject`/`WriteTlvInlineObject` methods — `ReadTlvObject` already handles nested TLV content.

### C# Style Guide

#### Naming Conventions

```csharp
// PascalCase for classes, methods, properties
public class CharacterService { }
public void LoadCharacter() { }
public string PlayerName { get; set; }

// camelCase for local variables, parameters
public void ProcessData(int itemId)
{
    var characterData = LoadData();
}

// _camelCase for private fields
private readonly ILogger _logger;

// UPPER_CASE for constants
public const int MAX_PLAYER_LEVEL = 100;
```

#### Code Organization

```csharp
// 1. Using statements
using System;
using System.Linq;
using Rathalos.Core.Protocol;

// 2. Namespace
namespace Rathalos.Servers.Game.Services
{
    // 3. Class documentation
    /// <summary>
    /// Manages character-related operations.
    /// </summary>
    public class CharacterService
    {
        // 4. Constants
        private const int MaxNameLength = 32;

        // 5. Fields
        private readonly ILogger<CharacterService> _logger;
        private readonly RathalosDbContext _context;

        // 6. Constructor
        public CharacterService(
            ILogger<CharacterService> logger,
            RathalosDbContext context)
        {
            _logger = logger;
            _context = context;
        }

        // 7. Public methods
        public async Task<Character> GetCharacterAsync(int id)
        {
            return await _context.Characters
                .AsNoTracking()
                .FirstOrDefaultAsync(c => c.Id == id);
        }

        // 8. Private methods
        private void ValidateCharacter(Character character)
        {
            if (string.IsNullOrEmpty(character.Name))
                throw new ArgumentException("Name required");
        }
    }
}
```

### XML Documentation

Document public APIs:

```csharp
/// <summary>
/// Creates a new character for the specified account.
/// </summary>
/// <param name="accountId">The account ID</param>
/// <param name="name">Character name (max 32 chars)</param>
/// <param name="gender">Character gender</param>
/// <returns>The created character</returns>
/// <exception cref="ArgumentException">If name is invalid</exception>
/// <exception cref="DuplicateNameException">If name already exists</exception>
public async Task<Character> CreateCharacterAsync(
    int accountId,
    string name,
    Gender gender)
{
    // Implementation
}
```

### Async/Await Best Practices

```csharp
// ✅ Good - Use async all the way
public async Task<List<Character>> GetCharactersAsync(int accountId)
{
    return await _context.Characters
        .Where(c => c.AccountId == accountId)
        .ToListAsync();
}

// ❌ Bad - Don't block on async
public List<Character> GetCharacters(int accountId)
{
    return _context.Characters
        .Where(c => c.AccountId == accountId)
        .ToListAsync()
        .Result; // NEVER DO THIS
}

// ✅ Good - ConfigureAwait for library code
public async Task<Character> GetCharacterAsync(int id)
{
    return await _context.Characters
        .FirstOrDefaultAsync(c => c.Id == id)
        .ConfigureAwait(false);
}
```

### Error Handling

```csharp
// ✅ Good - Specific exceptions
public async Task UpdateCharacterAsync(Character character)
{
    if (character == null)
        throw new ArgumentNullException(nameof(character));

    if (string.IsNullOrEmpty(character.Name))
        throw new ArgumentException("Name is required", nameof(character));

    try
    {
        _context.Update(character);
        await _context.SaveChangesAsync();
    }
    catch (DbUpdateException ex)
    {
        _logger.LogError(ex, "Failed to update character {Id}", character.Id);
        throw new DataException("Failed to save character", ex);
    }
}

// ❌ Bad - Catch all exceptions
public async Task UpdateCharacterAsync(Character character)
{
    try
    {
        _context.Update(character);
        await _context.SaveChangesAsync();
    }
    catch (Exception ex) // Too broad
    {
        // Swallowing exception
    }
}
```

### Dependency Injection

```csharp
// ✅ Good - Constructor injection
public class CharacterHandler
{
    private readonly ICharacterService _characterService;
    private readonly ILogger<CharacterHandler> _logger;

    public CharacterHandler(
        ICharacterService characterService,
        ILogger<CharacterHandler> logger)
    {
        _characterService = characterService;
        _logger = logger;
    }
}

// Register in Program.cs
builder.Services.AddScoped<ICharacterService, CharacterService>();
builder.Services.AddScoped<CharacterHandler>();
```

---

## Development Workflow

### Feature Development

1. **Create feature branch**:
   ```powershell
   git checkout -b feature/character-equipment
   ```

2. **Implement feature**:
   - Write code following standards
   - Add unit tests
   - Update documentation

3. **Test locally**:
   ```powershell
   dotnet test
   dotnet build --configuration Release
   ```

4. **Commit changes**:
   ```powershell
   git add .
   git commit -m "feat: Add character equipment system"
   ```

5. **Push and create PR**:
   ```powershell
   git push origin feature/character-equipment
   ```

### Commit Message Convention

Follow [Conventional Commits](https://www.conventionalcommits.org/):

```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

**Types:**
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation
- `style`: Code style (formatting)
- `refactor`: Code refactoring
- `perf`: Performance improvement
- `test`: Tests
- `chore`: Maintenance

**Examples:**
```
feat(character): Add equipment management
fix(protocol): Correct TLV deserialization bug
docs(wiki): Update installation guide
refactor(database): Optimize character queries
```

---

## Testing

### Unit Tests

Create tests in a separate test project:

```csharp
using Xunit;
using Moq;

public class CharacterServiceTests
{
    [Fact]
    public async Task CreateCharacter_ValidInput_ReturnsCharacter()
    {
        // Arrange
        var mockContext = new Mock<RathalosDbContext>();
        var service = new CharacterService(mockContext.Object);

        // Act
        var result = await service.CreateCharacterAsync(1, "TestChar", Gender.Male);

        // Assert
        Assert.NotNull(result);
        Assert.Equal("TestChar", result.Name);
    }

    [Theory]
    [InlineData(null)]
    [InlineData("")]
    [InlineData("   ")]
    public async Task CreateCharacter_InvalidName_ThrowsException(string name)
    {
        // Arrange
        var service = new CharacterService(/* dependencies */);

        // Act & Assert
        await Assert.ThrowsAsync<ArgumentException>(
            () => service.CreateCharacterAsync(1, name, Gender.Male));
    }
}
```

### Integration Tests

```csharp
public class DatabaseIntegrationTests : IClassFixture<DatabaseFixture>
{
    private readonly DatabaseFixture _fixture;

    public DatabaseIntegrationTests(DatabaseFixture fixture)
    {
        _fixture = fixture;
    }

    [Fact]
    public async Task SaveCharacter_PersistsToDatabase()
    {
        // Arrange
        using var context = _fixture.CreateContext();
        var character = new Character { Name = "Test" };

        // Act
        context.Characters.Add(character);
        await context.SaveChangesAsync();

        // Assert
        var saved = await context.Characters
            .FirstOrDefaultAsync(c => c.Name == "Test");
        Assert.NotNull(saved);
    }
}
```

### Run Tests

```powershell
# Run all tests
dotnet test

# Run specific test
dotnet test --filter "FullyQualifiedName=Rathalos.Tests.CharacterServiceTests.CreateCharacter_ValidInput_ReturnsCharacter"

# Run with coverage
dotnet test /p:CollectCoverage=true
```

---

## Debugging

### Visual Studio

1. **Set breakpoints** in code
2. **Press F5** to start debugging
3. **Use debugging windows**:
   - Locals (Alt+4)
   - Watch (Alt+3)
   - Call Stack (Ctrl+Alt+C)
   - Immediate (Ctrl+Alt+I)

### VS Code

1. **Install C# extension**
2. **Create `.vscode/launch.json`**:
   ```json
   {
     "version": "0.2.0",
     "configurations": [
       {
         "name": ".NET Core Launch (console)",
         "type": "coreclr",
         "request": "launch",
         "program": "${workspaceFolder}/GUI/Rathalos.ConsoleUI.World/bin/Debug/net10.0/Rathalos.ConsoleUI.World.dll",
         "args": [],
         "cwd": "${workspaceFolder}/GUI/Rathalos.ConsoleUI.World",
         "stopAtEntry": false
       }
     ]
   }
   ```
3. **Press F5** to start debugging

### Logging

Use structured logging:

```csharp
_logger.LogInformation("Character {CharacterId} loaded for account {AccountId}", 
    characterId, accountId);

_logger.LogWarning("Invalid item {ItemId} for character {CharacterId}", 
    itemId, characterId);

_logger.LogError(ex, "Failed to save character {CharacterId}", characterId);
```

### Database Query Logging

Enable in `appsettings.json`:

```json
{
  "Logging": {
    "LogLevel": {
      "Microsoft.EntityFrameworkCore.Database.Command": "Information"
    }
  }
}
```

---

## Next Steps

- [Contributing Guidelines](Contributing)
- [Protocol Documentation](Protocol-Documentation)
- [Architecture Overview](Architecture)
- [API Reference](API-Reference)

## Additional Resources

- [C# Coding Conventions](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/coding-style/coding-conventions)
- [Async Best Practices](https://docs.microsoft.com/en-us/archive/msdn-magazine/2013/march/async-await-best-practices-in-asynchronous-programming)
- [Entity Framework Core](https://docs.microsoft.com/en-us/ef/core/)
- [xUnit Documentation](https://xunit.net/)
