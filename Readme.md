# HoudiniPlus
HoudiniPlus Houdini Engine integration with Unreal Engine 4. It provides as alternative to the official plugin that aims to give lower level access, closer to the HAPI itself.

### Module
A the module level, HAPI_Initialize and HAPI_Cleanup are called int the startup and shutdown calls.

### HoudiniPlusSession
1. HoudiniPlusInProcessSession
2. etc.

### HoudiniPlusAssetLibrary
A UE4 asset that contains a file path to the HDA, a cached version of the HDA itself, and a list of the contained assets.

### HoudiniPlusAssetInfo
Metadata for the assets contained in a HoudiniPlusAssetLibrary.

### HoudiniPlusAssetInstance
An instance of an Asset.

### HoudiniPlusNode
+ Cook(CookOptions)
1. HoudiniPlusInputNode
   
### HoudiniPlusAttributeInfo