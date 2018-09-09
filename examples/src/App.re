[%bs.raw {|require('./App.css')|}];

[%bs.raw {|require('@reach/menu-button/styles.css')|}];

[%bs.raw {|require('@reach/dialog/styles.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <p className="App-intro">
        <button>
          <img src="http://placehold.it/20x20" alt="save" />
          <VisuallyHidden> ("test" |> ReasonReact.string) </VisuallyHidden>
        </button>
        (ReasonReact.string("To get started, edit"))
        <code> (ReasonReact.string(" src/App.re ")) </code>
        (ReasonReact.string("and save to reload."))
      </p>
      <div>
        <MenuButton.Menu>
          <MenuButton.MenuButton>
            ("Products" |> ReasonReact.string)
          </MenuButton.MenuButton>
          <MenuButton.MenuList>
            <MenuButton.MenuItem onSelect=(() => Js.log("Download"))>
              ("Download" |> ReasonReact.string)
            </MenuButton.MenuItem>
            <MenuButton.MenuLink
              component="a" to_="test" href="https://reach.tech/courses">
              ("Online Courses" |> ReasonReact.string)
            </MenuButton.MenuLink>
            <MenuButton.MenuLink
              to_="test2" component="a" href="https://reach.tech/ui">
              ("Reach UI" |> ReasonReact.string)
            </MenuButton.MenuLink>
          </MenuButton.MenuList>
        </MenuButton.Menu>
        <Dialog.Dialog isOpen=true>
          <p> ("hello" |> ReasonReact.string) </p>
        </Dialog.Dialog>
      </div>
    </div>,
};