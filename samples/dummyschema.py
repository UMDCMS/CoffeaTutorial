from coffea.nanoevents.schemas import BaseSchema
from coffea.nanoevents.schemas import zip_forms, nest_jagged_forms

class DummySchema(BaseSchema):
  mixins = {
      'Electron': "PtEtaPhiMLorentzVector",
      'Muon': 'PtEtaPhiMLorentzVector',
      'Jet': 'PtEtaPhiELorentzVector',
      'Subjet': 'PtEtaPhiELorentzVector',
  }

  def __init__(self, base_form):
    super().__init__(base_form)
    self._form["contents"] = self._build_collections(self._form["contents"])

  def _build_collections(self,branch_forms):
    output = {}

    ## Making the basic 
    for name in self.mixins:
      mixin = self.mixins.get(name, "NanoCollection")
      output[name] = zip_forms({
                        k[len(name) + 1 :]: branch_forms[k]
                        for k in branch_forms
                        if k.startswith(name + "_")
                    },
                    name,
                    record_name=mixin)

    nest_jagged_forms(output['Jet'],
                      output.pop('Subjet'),
                      'SubjetsCounts',
                      'Subjets')
    return output

  @property
  def behavior(self):
    from coffea.nanoevents.methods import base, vector
    behavior = {}
    behavior.update(base.behavior)
    behavior.update(vector.behavior)
    return behavior
