param (
    [string]$srcBranch,
    [string]$dstBranch
)

if (-not $srcBranch -or -not $dstBranch) {
    Write-Host "Syntax: .\fromto.ps1 [src branch] [dst branch]"
    exit 1
}

git checkout $dstBranch

if ($srcBranch -eq "docs") {
  git restore --source $srcBranch -- License assets TEM
  git restore --staged assets/Doxyfile

  Move-Item -Path "assets" -Destination "docs" -Force
}
else {
  git restore --source $srcBranch -- License docs TEM

  if ($dstBranch -eq "docs") {
    Move-Item -Path "docs" -Destination "assets" -Force
  }
}

Write-Host "Don't forget to add and commit changes and build docs if needed!"

exit 0
