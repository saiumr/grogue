#include "composite_description_drawer.hpp"

GridObjectDrawer::DrawResources CompositeDescriptionDrawer::GetObject(component::GridPanel* panel, int index) {
    auto objectIdx = GameData::Instance()->GetCompositePanel()->GetComponent<component::GridPanel>()->GetHoverIndex();
    auto it = ComposeConfigStorage::begin();
    std::advance(it, objectIdx);
    auto& materials = it->second.materials;

    int materialIdx = index;
    auto& material = materials[materialIdx];

    auto materialConfig = ObjectConfigStorage::Find(material.id);

    return {materialConfig->image, material.num};
}