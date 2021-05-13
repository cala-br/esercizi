from giulio.base_application import BaseApplication
from giulio.learning_switch import LearningSwitch

class ArpResponder(BaseApplication):
  def __init__(self):
    super().__init__()
    self._arpTable = {}

  def handlePacketIn(self):
    pass

  def handleSwitchFeatures(self):
    pass


  def asLearningSwitch(self):
    return LearningSwitch()