# Copilot Instructions

## Directives de projet
- For TLV nested sub-structures, use the existing ReadTlvObject/WriteTlvObject helpers. Do not create separate ReadTlvInlineObject/WriteTlvInlineObject methods — ReadTlvObject already handles nested TLV content.