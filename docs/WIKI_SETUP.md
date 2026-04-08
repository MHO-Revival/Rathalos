# Wiki Setup Guide

Quick guide to publish the documentation to your GitHub Wiki.

## Method 1: Using GitHub Web Interface

### Step 1: Enable Wiki

1. Go to your repository: `https://github.com/MHO-Revival/Rathalos`
2. Click **Settings** tab
3. Scroll to **Features** section
4. Check ✅ **Wikis**

### Step 2: Create Pages Manually

1. Click **Wiki** tab
2. Click **Create the first page**
3. Copy content from `docs/wiki/Home.md`
4. Save as "Home"
5. Repeat for each wiki page:
   - Installation-Guide
   - Server-Configuration
   - Protocol-Documentation
   - Tools-Documentation
   - Troubleshooting
   - Development-Guide

## Method 2: Using Git (Recommended)

### Step 1: Clone Wiki Repository

```powershell
# Clone the wiki (must enable wiki first via web interface)
git clone https://github.com/MHO-Revival/Rathalos.wiki.git

# Or if already exists
cd Rathalos.wiki
git pull
```

### Step 2: Copy Documentation

```powershell
# From your project root
Copy-Item docs/wiki/*.md Rathalos.wiki/ -Force

# Or on Linux/macOS
cp docs/wiki/*.md Rathalos.wiki/
```

### Step 3: Commit and Push

```powershell
cd Rathalos.wiki
git add .
git commit -m "Add comprehensive documentation"
git push origin master
```

### Step 4: Verify

Visit: `https://github.com/MHO-Revival/Rathalos/wiki`

## Method 3: Using PowerShell Script

Save this as `publish-wiki.ps1`:

```powershell
# publish-wiki.ps1
param(
    [string]$WikiPath = "../Rathalos.wiki"
)

Write-Host "Publishing wiki documentation..." -ForegroundColor Green

# Clone wiki if not exists
if (-not (Test-Path $WikiPath)) {
    Write-Host "Cloning wiki repository..."
    git clone https://github.com/MHO-Revival/Rathalos.wiki.git $WikiPath
}

# Copy files
Write-Host "Copying documentation files..."
Copy-Item docs/wiki/*.md $WikiPath -Force

# Commit and push
cd $WikiPath
git add .
git commit -m "Update documentation - $(Get-Date -Format 'yyyy-MM-dd')"
git push origin master

Write-Host "✅ Wiki published successfully!" -ForegroundColor Green
Write-Host "View at: https://github.com/MHO-Revival/Rathalos/wiki" -ForegroundColor Cyan
```

Run it:
```powershell
.\publish-wiki.ps1
```

## Wiki Page Order

Create pages in this order for best navigation:

1. **Home** (landing page)
2. **Installation-Guide** (first steps)
3. **Server-Configuration** (setup)
4. **Protocol-Documentation** (technical)
5. **Tools-Documentation** (utilities)
6. **Development-Guide** (for contributors)
7. **Troubleshooting** (help)

## Customize Sidebar

Create `_Sidebar.md` in wiki:

```markdown
### 🏠 Getting Started
- [Home](Home)
- [Installation Guide](Installation-Guide)
- [Quick Start](Quick-Start-Tutorial)

### ⚙️ Configuration
- [Server Configuration](Server-Configuration)
- [Client Setup](Client-Configuration)

### 📚 Documentation
- [Protocol Documentation](Protocol-Documentation)
- [Tools Documentation](Tools-Documentation)
- [API Reference](API-Reference)

### 🛠️ Development
- [Development Guide](Development-Guide)
- [Architecture](Architecture)
- [Contributing](Contributing)

### 🆘 Support
- [Troubleshooting](Troubleshooting)
- [FAQ](FAQ)
```

## Create Footer

Create `_Footer.md` in wiki:

```markdown
---
**Rathalos** - Monster Hunter Online Server Emulator | [GitHub](https://github.com/MHO-Revival/Rathalos) | [Discord](https://discord.gg/mho-revival)
```

## Enable Wiki Search

GitHub Wiki search is automatic once pages are created!

## Best Practices

1. **Use descriptive titles** - Clear page names
2. **Add internal links** - Connect related pages
3. **Keep it updated** - Sync with code changes
4. **Use code blocks** - Format code examples properly
5. **Add images** - Screenshots help understanding
6. **Version information** - Note which version docs apply to

## Adding Images

1. **Upload images** to GitHub Issues:
   - Create new issue
   - Drag image to comment
   - Copy generated URL
   - Close issue (or keep as asset storage)

2. **Reference in wiki**:
   ```markdown
   ![Server Architecture](https://user-images.githubusercontent.com/.../architecture.png)
   ```

## Troubleshooting

### Wiki Not Appearing

**Problem**: Wiki tab doesn't show

**Solution**:
- Enable Wikis in repository Settings → Features
- Create at least one page via web interface

### Permission Denied When Pushing

**Problem**: Can't push to wiki repo

**Solution**:
```powershell
# Configure Git credentials
git config credential.helper store

# Or use SSH instead of HTTPS
git remote set-url origin git@github.com:MHO-Revival/Rathalos.wiki.git
```

### Wiki Repository Not Found

**Problem**: Can't clone wiki

**Solution**:
- Wiki must be enabled first
- Create first page via web interface
- Then clone will work

## Automated Wiki Updates

Add to your CI workflow (`.github/workflows/wiki.yml`):

```yaml
name: Update Wiki

on:
  push:
    branches: [ main ]
    paths:
      - 'docs/wiki/**'

jobs:
  update-wiki:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: Publish to Wiki
        uses: SwiftDocOrg/github-wiki-publish-action@v1
        with:
          path: docs/wiki
        env:
          GH_PERSONAL_ACCESS_TOKEN: ${{ secrets.GH_PAT }}
```

## Next Steps

After setting up the wiki:

1. ✅ Review all pages for accuracy
2. ✅ Add any missing information
3. ✅ Create additional pages as needed
4. ✅ Set up sidebar navigation
5. ✅ Add footer with links
6. ✅ Announce to community

---

**Wiki documentation complete! 🎉**

View your wiki at: `https://github.com/MHO-Revival/Rathalos/wiki`
