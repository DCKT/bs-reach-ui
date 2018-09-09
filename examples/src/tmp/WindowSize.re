[@bs.module "@reach/window-size"]
external reactClass : ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type windowSize = {
  width: int,
  height: int,
};

type children = windowSize => ReasonReact.reactElement;

let make = (children: children) =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);