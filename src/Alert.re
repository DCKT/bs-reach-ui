[@bs.deriving jsConverter]
type alertType = [ | `assertive | `polite];

[@bs.deriving abstract]
type commonjsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
  [@bs.as "type"]
  type_: string,
};

[@bs.module "@reach/alert"]
external reactClass : ReasonReact.reactClass = "default";

let make = (~type_: alertType, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      commonjsProps(
        ~className=Js.Nullable.fromOption(className),
        ~style=Js.Nullable.fromOption(style),
        ~type_=alertTypeToJs(type_),
      ),
    children,
  );