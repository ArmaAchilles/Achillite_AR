[EntityEditorProps(category: "GameScripted/Modules", description: "Module Base Class", color: "255 0 0 255")]
class ACL_ModuleEntityBaseClass: GenericEntityClass
{
};
class ACL_ModuleEntityBase: GenericEntity
{
	protected SCR_EditableEntityComponent m_entity;
	
	override event void EOnInit(IEntity owner)
	{
		// Do not run module in World Editor
		if (!GetGame().InPlayMode())
			return;
		m_entity = SCR_EditableEntityComponent.Cast(this.FindComponent(SCR_EditableEntityComponent));
		
		OnPlace(GetPos(), GetAttachedEntity());
	}
	
	protected void OnPlace(vector pos, SCR_EditableEntityComponent entity);
	
	protected vector GetPos()
	{
		vector pos = {0, 0, 0};
		if (m_entity)
			m_entity.GetPos(pos);
		return pos;
	}
	
	protected SCR_EditableEntityComponent GetAttachedEntity() {
		SCR_HoverEditableEntityFilter hoverFilter = SCR_HoverEditableEntityFilter.Cast(SCR_HoverEditableEntityFilter.GetInstance(EEditableEntityState.HOVER, true));
		if (!hoverFilter)
			return null;
		
		bool isDelegate;
		SCR_EditableEntityComponent entityUnderCursor = hoverFilter.GetEntityUnderCursor(isDelegate);
		if (!isDelegate)
			return null;
		
		return entityUnderCursor;
	}
	
	protected void Delete()
	{
		if (!m_entity)
			return;
		m_entity.Delete();
	}
};
