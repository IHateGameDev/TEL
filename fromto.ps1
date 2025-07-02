param (
  [string]$srcBranch,
  [string]$dstBranch
)

if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
  Write-Host "Git is not installed or not available in the command line."
  exit 1
}

if (-not $srcBranch -or -not $dstBranch) {
  Write-Host "Syntax: .\fromto.ps1 [src branch] [dst branch]"
  exit 1
}

try {
  git checkout $dstBranch
} catch {
  Write-Host "Error switching to branch $dstBranch: $_"
  exit 1
}

try {
  git restore --source $srcBranch -- fromto.ps1 fromto.sh License TEL

  if ($srcBranch -eq "docs") {
    git restore --source $srcBranch -- Pages
    Move-Item -Path "Pages" -Destination "docs" -Force
  } else {
    git restore --source $srcBranch -- docs

    if ($dstBranch -eq "docs") {
      Move-Item -Path "docs" -Destination "Pages" -Force
    }
  }
} catch {
  Write-Host "Error copying files: $_"
  exit 1
}

Write-Host "Don't forget to add and commit changes, and build docs if needed!"

exit 0

