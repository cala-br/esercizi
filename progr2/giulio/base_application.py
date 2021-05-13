from giulio.learning_switch import LearningSwitch
from giulio.arp_responder import ArpResponder

from enum import Enum

class HandlerState(Enum):
  ActionHandled = 0
  ActionPassed = 1

class HandlerKind(Enum):
  ArpResponder = 0
  LearningSwitch = 1


class BaseApplication:
  @staticmethod
  def create(*args, **kwargs):
    return BaseApplication(*args, **kwargs)
  
  def __init__(self, *args, **kwargs):
    self.eventHandlers = []


  def addFlow(self):
    pass


  def handleSwitchFeatures(self):
    for handler in self.eventHandlers:
      handler.handleSwitchFeatures()

  def handlePacketIn(self):
    return any(
      handler.handlePacketIn() == HandlerState.ActionHandled
      for handler in self.eventHandlers 
    )


  def use(self, what, *args, **kwargs):
    handler = {
      HandlerKind.ArpResponder: ArpResponder,
      HandlerKind.LearningSwitch: LearningSwitch,
    }[what]
    
    return self._addHandler(handler(*args, **kwargs))


  # In alternativa a use()
  def useArpResponder(self, *args, **kwargs):
    return self._addHandler(ArpResponder(*args, **kwargs))

  def useLearningSwitch(self, *args, **kwargs):
    return self._addHandler(LearningSwitch(*args, **kwargs))


  def _addHandler(self, handler):
    self.eventHandlers.append(handler)
    return self
