import bb.cascades 1.2
import ludin.datamodels 1.0
NavigationPane {
    id: nav
    onPopTransitionEnded: {
        page.destroy();
        listview.clearSelection();
    }
    Page {
        id: page
        Container {
            ListView {
                id: listview
                dataModel: MyDataModel {
                    id: people
                    source: "people.json"
                }
                attachedObjects: [
                    ComponentDefinition {
                        id: itemPageDefinition
                        source: "PersonDetails.qml"
                    }
                ]
                onTriggered: {
                    if (indexPath.length > 1) {
                        var person = people.data(indexPath);
                        var personDetails = itemPageDefinition.createObject();
                        personDetails.person = person
                        nav.push(personDetails);
                    }
                }
                listItemComponents: [
                    ListItemComponent {
                        type: "category"
                        CustomListItem {
                            id: customListItem
                            dividerVisible: true
                            Label {
                                text: ListItemData.value
                                // Apply a text style to create a large, bold font with
                                // a specific color
                                textStyle {
                                    base: SystemDefaults.TextStyles.BigText
                                    fontWeight: FontWeight.Bold
                                    color: Color.create("#7a184a")
                                }
                            }
                        }
                    },
                    ListItemComponent {
                        type: "person"
                        StandardListItem {
                            id: standardListItem
                            title: ListItemData.name
                            description: ListItemData.born
                            status: ListItemData.spouse
                            imageSource: "asset:///pics/" + ListItemData.pic
                            contextActions: [
                                ActionSet {
                                    DeleteActionItem {
                                        onTriggered: {
                                            var myview = standardListItem.ListItem.view;
                                            var datamodel = myview.dataModel;
                                            var indexPath = myview.selected();
                                            datamodel.removeItem(indexPath);
                                        }
                                    } // DeleteActionItem
                                } // ActionSet
                            ] // ContextActions
                        }
                    }
                ]
            }
        }
    }
}
