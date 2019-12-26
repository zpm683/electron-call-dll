{
  "targets": [
    {
      "target_name": "demo",
      "sources": [ "native/demo.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
