[EntityEditorProps(category: "GameScripted/Modules", description: "Edit Intel Module", color: "255 0 0 255")]
class ACL_ModuleEditIntelEntityClass: ACL_ModuleEntityBaseClass
{
};

class ACL_ModuleEditIntelEntity: ACL_ModuleEntityBase
{
	string m_message = "Hello World!";
	string m_channelName = "Global";
	
	override void OnPlace(vector pos, SCR_EditableEntityComponent entity)
	{
		SCR_AttributesManagerEditorComponent attributesManager = SCR_AttributesManagerEditorComponent.Cast(SCR_AttributesManagerEditorComponent.GetInstance(SCR_AttributesManagerEditorComponent));
		if (!entity)
		{
			Delete();
			return;
		};
		array<Managed> entities = {entity};
		attributesManager.StartEditing(entities);
		
		Delete();
	}
};
