[ComponentEditorProps(category: "GameScripted/Editor (Editables)", description: "", icon: "WBData/ComponentEditorProps/componentEditor.png")]
class ACL_EditableModuleComponentClass: SCR_EditableEntityComponentClass {};

/** @ingroup Editable_Entities
*/

/*!
Component defining editable modules.

Every entities with this component is registered locally to a list managed by SCR_EditableEntityCore.
*/
class ACL_EditableModuleComponent : SCR_EditableEntityComponent
{
	override SCR_EditableEntityComponent EOnEditorPlace(out SCR_EditableEntityComponent parent, SCR_EditableEntityComponent recipient, EEditorPlacingFlags flags, bool isQueue)
	{
		return this;
	}
}
